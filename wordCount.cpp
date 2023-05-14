#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("参数错误！正确格式为：%s [-c|-w] [input_file_name]\n", argv[0]);
        return 1;
    }

    char* param = argv[1];
    char* filename = argv[2];

    if (strcmp(param, "-c") != 0 && strcmp(param, "-w") != 0) {
        printf("未知参数：%s\n", param);
        return 1;
    }

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("无法打开文件 %s\n", filename);
        exit(1);
    }

    char c;
    int char_count = 0, word_count = 0;
    int is_word = 0; // 标记是否正在处理单词

    while ((c = fgetc(fp)) != EOF) {
        char_count++; // 统计字符数
        if (c == ' ' || c == '\n' || c == '\t' || c == ',') {
            // 以空格、换行、制表符或逗号作为分隔符，判断当前是否正在处理单词
            if (is_word) {
                word_count++;
                is_word = 0;
            }
        } else {
            // 其他字符均视为单词的一部分
            is_word = 1;
        }
    }

    // 处理最后一个单词
    if (is_word) {
        word_count++;
    }

    if (strcmp(param, "-c") == 0) {
        printf("字符数为：%d\n", char_count);
    } else {
        printf("单词数为：%d\n", word_count);
    }

    fclose(fp);
    return 0;
}
