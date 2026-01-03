#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct MapNodeValue {
    char *s;
    struct MapNodeValue *next;
} MapNodeValue;

struct MapNode {
    char *key;
    struct MapNodeValue *value;
    struct MapNode *next;
} MapNode;

struct MapNode* getHash(struct MapNode *map_node, char *s) {
    int str_length = strlen(s);
    int key_f[26] = { 0 };
    for (int i = 0; i < str_length; i++) {
        key_f[s[i] - 'a'] += 1;
    }
    int key_size = 0;
    for (int i = 0; i < 26; i++) {
        int n = key_f[i];
        if (n == 0) {
            key_size += 1;
        }
        while (n > 0) {
            n /= 10;
            key_size += 1;
        }
    }

    char *key = (char *) malloc(sizeof(char) * (key_size + 26 + 1));
    memset(key, 0, sizeof(char) * (key_size + 26 + 1));
    int key_index = 0;
    for (int i = 0; i < 26; i++) {
        int n = key_f[i];
        
        if (n == 0) {
            key[key_index++] = '0';
        }
        while (n > 0) {
            char c = (n % 10) + 48;
            n /= 10;
            key[key_index++] = c;
        }
        key[key_index++] = '$';
    }
    
    struct MapNode *p = map_node;
    while(p != NULL) {
        if (strcmp(p->key, key) == 0) {
            break;
        }
        p = p->next;
    }

    if (p == NULL) {
        p = (struct MapNode *) malloc(sizeof(struct MapNode));
        p->key = key;
        p->next = NULL;
        p->value = NULL;
        struct MapNode *find_vp = map_node;
        while (find_vp != NULL && find_vp->next != NULL) {
            find_vp = find_vp->next;
        }
        if (find_vp != NULL) {
            find_vp->next = p;
        }
    }
    

    struct MapNodeValue *p_value = p->value;
    while (p_value != NULL && p_value->next != NULL) {
        p_value = p_value->next;
    }

    if (p_value == NULL) {
        p->value = (struct MapNodeValue *) malloc(sizeof(struct MapNodeValue));
        p_value = p->value;
    } else {
        p_value->next = (struct MapNodeValue *) malloc(sizeof(struct MapNodeValue));
        p_value = p_value->next;
    }
    p_value->next = NULL;
    p_value->s = s;
    return p;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    char ***res = (char ***) malloc(sizeof(char **) * strsSize);
    for (int i = 0; i < strsSize; i++) {
        (res[i]) = (char **) malloc(sizeof(char *) * strsSize);
    }
    (*returnColumnSizes) = (int *) malloc(sizeof(int) * strsSize);

    memset((*returnColumnSizes), 0, sizeof(int) * strsSize);

    struct MapNode *p = getHash(NULL, strs[0]);
    for (int i = 1; i < strsSize; i++) {
        getHash(p, strs[i]);
    }
    (*returnSize) = 0;

    while (p != NULL) {
        struct MapNodeValue *v = p->value;
        int r = 0;
        if (v != NULL) {
            r = 1;
        }

        while (v != NULL) {
            res[(*returnSize)][(*returnColumnSizes)[(*returnSize)]] = v->s;
            (*returnColumnSizes)[(*returnSize)] += 1;
            v = v->next;
        }

        if (r == 1) {
            (*returnSize) += 1;
        }

        p = p->next;
    }

    return res;
}