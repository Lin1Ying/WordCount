#include <stdio.h>
#include <stdbool.h>

int main() {
    FILE* file = fopen("E://code//WordCount//input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int charCount = 0;
    int wordCount = 0;
    bool inWord = false;

    char c;
    while ((c = fgetc(file)) != EOF) {
        charCount++; // 读取的每个字符都计入字符数

        // 如果当前字符是逗号或空格，并且我们之前在一个单词中，则我们结束了一个单词
        if ((c == ',' || c == ' ') && inWord) {
            inWord = false;
        }

        // 如果当前字符不是逗号也不是空格，并且我们之前不在单词中，则我们开始了一个新单词
        if (!(c == ',' || c == ' ') && !inWord) {
            inWord = true;
            wordCount++; // 开始新单词，增加单词计数
        }
    }

   

    fclose(file);

    printf("Character count: %d\n", charCount);
    printf("Word count: %d\n", wordCount);

    return 0;
}
