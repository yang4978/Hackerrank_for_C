//https://www.hackerrank.com/challenges/post-transition/problem

#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING_LENGTH 6

struct package
{
	char* id;
	int weight;
};

typedef struct package package;

struct post_office
{
	int min_weight;
	int max_weight;
	package* packages;
	int packages_count;
};

typedef struct post_office post_office;

struct town
{
	char* name;
	post_office* offices;
	int offices_count;
};

typedef struct town town;


void print_all_packages(town t) {
    printf("%s:\n",t.name);
    for(int i=0;i<t.offices_count;i++){
        printf("\t%d:\n",i);
        for(int j=0;j<t.offices[i].packages_count;j++){
            printf("\t\t%s\n",t.offices[i].packages[j].id);
        }
    }
}

void send_all_acceptable_packages(town* source, int source_office_index, town* target, int target_office_index) {	
    post_office sender = source[0].offices[source_office_index];
    post_office receiver = target[0].offices[target_office_index];

    int* index_temp = (int*) malloc(sizeof(int)*sender.packages_count);
    int delete_num = 0;

    for(int i=0;i<sender.packages_count;i++){
        if (sender.packages[i].weight >= receiver.min_weight &&
            sender.packages[i].weight <= receiver.max_weight) {
            receiver.packages_count++;
            receiver.packages = realloc(receiver.packages,sizeof(package) * receiver.packages_count);
            receiver.packages[receiver.packages_count - 1] = sender.packages[i];
            index_temp[delete_num] = i;
            delete_num++;
        }
    }

    for(int i=0;i<delete_num;i++){
        sender.packages_count--;
        for (int j = index_temp[i]; j < sender.packages_count; j++) {
          sender.packages[j] = sender.packages[j + 1];
        }
        sender.packages =
            realloc(sender.packages, sizeof(package) * sender.packages_count);
    }
    free(index_temp);
    target[0].offices[target_office_index] = receiver;
    source[0].offices[source_office_index] = sender;
}

town town_with_most_packages(town* towns, int towns_count) {
    int max = 0;
    town result;
    for(int i=0;i<towns_count;i++){
        int sum = 0;
        for(int j=0;j<towns[i].offices_count;j++){
            sum += towns[i].offices[j].packages_count;
        }
        if(sum>max){
            max = sum;
            result = towns[i];
        }
    }
    return result;
}

town* find_town(town* towns, int towns_count, char* name) {
    town* result = (town*)malloc(sizeof(town)*1);
    int num = 0;
    for(int i=0;i<towns_count;i++){
        if(strcmp(towns[i].name,name)==0){
            result[0] = towns[i];
            num ++;
        }
    }
    return result;
}

int main()
{
	int towns_count;
	scanf("%d", &towns_count);
	town* towns = malloc(sizeof(town)*towns_count);
	for (int i = 0; i < towns_count; i++) {
		towns[i].name = malloc(sizeof(char) * MAX_STRING_LENGTH);
		scanf("%s", towns[i].name);
		scanf("%d", &towns[i].offices_count);
		towns[i].offices = malloc(sizeof(post_office)*towns[i].offices_count);
		for (int j = 0; j < towns[i].offices_count; j++) {
			scanf("%d%d%d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
			towns[i].offices[j].packages = malloc(sizeof(package)*towns[i].offices[j].packages_count);
			for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
				towns[i].offices[j].packages[k].id = malloc(sizeof(char) * MAX_STRING_LENGTH);
				scanf("%s", towns[i].offices[j].packages[k].id);
				scanf("%d", &towns[i].offices[j].packages[k].weight);
			}
		}
	}
	int queries;
	scanf("%d", &queries);
	char town_name[MAX_STRING_LENGTH];
	while (queries--) {
		int type;
		scanf("%d", &type);
		switch (type) {
		case 1:
			scanf("%s", town_name);
			town* t = find_town(towns, towns_count, town_name);
			print_all_packages(*t);
			break;
		case 2:
			scanf("%s", town_name);
			town* source = find_town(towns, towns_count, town_name);
			int source_index;
			scanf("%d", &source_index);
			scanf("%s", town_name);
			town* target = find_town(towns, towns_count, town_name);
			int target_index;
			scanf("%d", &target_index);
			send_all_acceptable_packages(source, source_index, target, target_index);
			break;
		case 3:
			printf("Town with the most number of packages is %s\n", town_with_most_packages(towns, towns_count).name);
			break;
		}
	}
	return 0;
}

