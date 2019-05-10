//https://www.hackerrank.com/challenges/structuring-the-document/problem

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};

char **word_split(char *word, char *split_char) {
  char **result = (char **)malloc(1 * sizeof(char *));
  char *token = strtok(word, split_char);
  result[0] = token;
  int num = 1;

  while (token != NULL) {
    num++;
    result = (char **)realloc(result, num * sizeof(char *));
    token = strtok(NULL, split_char);
    result[num - 1] = token;
  }

  return result;
}

struct document get_document(char *text) {
  struct document Doc;
  char **temp_para = word_split(text, "\n");
  int para_num = 0;
  while (temp_para[para_num] != NULL) para_num++;
  
  Doc.data = (struct paragraph *)malloc(para_num * sizeof(struct paragraph));
  Doc.paragraph_count = para_num;

  for (int i = 0; i < para_num; i++) {
    char **temp_sen = word_split(temp_para[i], ".");
    int sen_num = 0;
    while (temp_sen[sen_num] != NULL) sen_num++;
    
    Doc.data[i].data = (struct sentence *)malloc(sen_num * sizeof(struct sentence));
    Doc.data[i].sentence_count = sen_num;

    for (int j = 0; j < sen_num; j++) {
      char **temp_word = word_split(temp_sen[j], " ");
      int word_num = 0;
      while (temp_word[word_num] != NULL) word_num++;
      
      Doc.data[i].data[j].data =
          (struct word *)malloc(word_num * sizeof(struct word));
      Doc.data[i].data[j].word_count = word_num;

      for (int k = 0; k < word_num; k++) {
        Doc.data[i].data[j].data[k].data = temp_word[k];
      }
    }
  }

  return Doc;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return Doc.data[n-1].data[m-1].data[k-1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) { 
    return Doc.data[m-1].data[k-1];
}

struct paragraph kth_paragraph(struct document Doc, int k) {
    return Doc.data[k-1];
}

