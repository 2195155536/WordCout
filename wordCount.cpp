#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("����������ȷ��ʽΪ��%s [-c|-w] [input_file_name]\n", argv[0]);
        return 1;
    }

    char* param = argv[1];
    char* filename = argv[2];

    if (strcmp(param, "-c") != 0 && strcmp(param, "-w") != 0) {
        printf("δ֪������%s\n", param);
        return 1;
    }

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("�޷����ļ� %s\n", filename);
        exit(1);
    }

    char c;
    int char_count = 0, word_count = 0;
    int is_word = 0; // ����Ƿ����ڴ�����

    while ((c = fgetc(fp)) != EOF) {
        char_count++; // ͳ���ַ���
        if (c == ' ' || c == '\n' || c == '\t' || c == ',') {
            // �Կո񡢻��С��Ʊ���򶺺���Ϊ�ָ������жϵ�ǰ�Ƿ����ڴ�����
            if (is_word) {
                word_count++;
                is_word = 0;
            }
        } else {
            // �����ַ�����Ϊ���ʵ�һ����
            is_word = 1;
        }
    }

    // �������һ������
    if (is_word) {
        word_count++;
    }

    if (strcmp(param, "-c") == 0) {
        printf("�ַ���Ϊ��%d\n", char_count);
    } else {
        printf("������Ϊ��%d\n", word_count);
    }

    fclose(fp);
    return 0;
}
