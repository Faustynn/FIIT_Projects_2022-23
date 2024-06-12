/*
Your task is to implement the dynamic set abstract data type using a hash table. The following operations should be supported:
i - insert - inserting a new item into the table
s - search - search for an item by key
u - update - adjustment of the item (specifically the balance on the account) according to the key
d - delete - removing an item from the table by key

Items represent people, consisting of first name, last name, date of birth, and a number representing the financial balance in the person's account.
The key is the combination of full name and date of birth.
Each person has a unique key.

Each operation must also be treated for possible operation failure, in which case the text " failed" is printed on the output in a separate line.
A failure is, for example, when we try to look up a person who is not in the data structure, or when we try to insert a duplicate person into the data structure.

The input of the program is the individual operations for the hash table, where each operation is located in a separate line.
A line always begins with the letter specifying the operation (i.e., i, s, u, or d), followed by the data required for that operation.
The insert operation needs all the data to insert the given item, i.e. first name, last name, date of birth and initial account balance (positive number with precision of 2 digits, e.g. euros and cents).
The search operation only uses the key
        The update operation needs a key, followed by a modification of the account balance (i.e. a number with a precision of 2 digits, e.g. euros and cents). In the case of a negative value, the update operation is valid only if it does not cause a negative balance on the account of the given person (i.e. the balance on the account must always be positive).
The delete operation only uses the key.

The output is the items found using the search operations and the failure report of the given operation.
Each item/message is on a separate line.

Do 03.04.2024, 18:00

Ukážkový vstup
i Thomas Sanford 1.1.2001 2017,81
i Nathan Flores 18.4.2002 6689,79
i Michelle Palmer 12.7.1999 7205,98
i Angelica Olsen 25.2.1991 6511,68
i Kevin Taylor 21.9.1969 7573,79
i Brian Hutchinson 5.9.1953 1531,69
i Joseph Hunter 15.5.1986 805,16
i Anthony White 6.5.1958 8013,22
i James Anderson 23.4.2002 7694,99
i Lori Mcknight 20.8.1976 1584,38
i Christopher Bryant 28.2.1962 229,57
i Kayla Jones 3.6.1962 9065,65
i Hannah West 2.2.1993 8237,84
i Jocelyn Frey 11.8.1954 3762,70
i Megan Collins 29.12.1988 7481,26
i Victoria Peck 6.9.1988 5301,50
i Jason Stafford 18.1.1974 2866,75
i Jean Johnson 27.3.1988 6950,36
i Grace Obrien 22.6.1981 2796,93
i Laura Ward 20.1.1999 7579,02
u Brian Hutchinson 5.9.1953 2073,09
u James Anderson 23.4.2002 -329,97
s Megan Collins 29.12.1988
u Kayla Jones 3.6.1962 2179,57
u Jocelyn Frey 11.8.1954 -985,99
u Hannah West 2.2.1993 457,97
u Angelica Olsen 25.2.1991 -1504,94
s Jason Stafford 18.1.1974
s Hannah West 2.2.1993
u Lori Mcknight 20.8.1976 1081,23
s Thomas Sanford 1.1.2001
u Thomas Sanford 1.1.2001 1514,85
u Angelica Olsen 25.2.1991 569,20
u Brian Hutchinson 5.9.1953 -2363,20
u Kayla Jones 3.6.1962 -206,37
u Nathan Flores 18.4.2002 -1100,55
d Grace Obrien 22.6.1981
u Laura Ward 20.1.1999 -1195,77
s James Anderson 23.4.2002
s Christopher Bryant 28.2.1962
s Brian Hutchinson 5.9.1953
i Christopher Powell 6.2.1966 91,21
u Christopher Bryant 28.2.1962 1511,66
u Jason Stafford 18.1.1974 246,09
u Kevin Taylor 21.9.1969 -2010,75
u Brian Hutchinson 5.9.1953 1384,48
u Jason Stafford 18.1.1974 -495,16
u Kayla Jones 3.6.1962 340,55
s Christopher Bryant 28.2.1962
u Brian Hutchinson 5.9.1953 -2387,11
u Michelle Palmer 12.7.1999 1737,77
s Megan Collins 29.12.1988
u Brian Hutchinson 5.9.1953 -2069,00
u Jason Stafford 18.1.1974 580,80
u Angelica Olsen 25.2.1991 1553,44
s Thomas Sanford 1.1.2001
u Nathan Flores 18.4.2002 589,51
u Kevin Taylor 21.9.1969 852,81
s James Anderson 23.4.2002
u Lori Mcknight 20.8.1976 -2189,98
u James Anderson 23.4.2002 -2448,33
u Kayla Jones 3.6.1962 650,09
u Laura Ward 20.1.1999 767,51
s Brian Hutchinson 5.9.1953
s Angelica Olsen 25.2.1991
s Kevin Taylor 21.9.1969
s Michelle Palmer 12.7.1999
u Jean Johnson 27.3.1988 716,98
u Angelica Olsen 25.2.1991 990,06
u Brian Hutchinson 5.9.1953 906,66
u Thomas Sanford 1.1.2001 -1269,26
s Thomas Sanford 1.1.2001
u Angelica Olsen 25.2.1991 -738,82
s Laura Ward 20.1.1999
s Joseph Hunter 15.5.1986
s Jean Johnson 27.3.1988
u Joseph Hunter 15.5.1986 -2400,21
d Hannah West 2.2.1993
s Michelle Palmer 12.7.1999
u Michelle Palmer 12.7.1999 -660,55
i Traci James 13.2.1991 39,89
u Victoria Peck 6.9.1988 1290,12
s Thomas Sanford 1.1.2001
u Thomas Sanford 1.1.2001 705,46
u Anthony White 6.5.1958 -1977,22
s Christopher Powell 6.2.1966
u Jason Stafford 18.1.1974 -1897,53
u Thomas Sanford 1.1.2001 -200,94
i Michael Jordan 20.3.1994 6683,23
s Megan Collins 29.12.1988
u Jean Johnson 27.3.1988 447,07
s Kevin Taylor 21.9.1969
u Joseph Hunter 15.5.1986 460,05
u Jean Johnson 27.3.1988 -2453,37
s Jean Johnson 27.3.1988
i Sean Wade 10.3.1985 7598,93
s Christopher Bryant 28.2.1962
i Zoe Meza 19.11.1995 5522,63
i Patricia Salinas 9.4.2000 7818,62
s Harry Potter 12.5.1995
s Laura Ward 20.1.1999

Ukážkový výstup
7481,26
2866,75
8695,81
2017,81
7365,02
229,57
1241,58
1741,23
7481,26
update failed
3532,66
7365,02
238,95
7129,38
6415,85
8943,75
2263,40
7150,76
805,16
7667,34
update failed
8943,75
2263,40
91,21
7481,26
6415,85
5661,04
1741,23
search failed
7150,76
*/


#include <stdio.h>
#include <stdlib.h>
#define HASHMAP_SIZE 2000
#define FNV_OFFSET_BASIS 2166136261u
#define FNV_PRIME 16777619u
#define ROTL32(x, r) (((x) << (r)) | ((x) >> (32 - (r))))

int prenos=0;

typedef struct DATA_STRUCT {
    float balance;
    unsigned int info_key;
    struct DATA_STRUCT *next;
} DATA;  // define data struct
typedef struct HASHMAP {
    DATA* data[HASHMAP_SIZE];
} HASHMAP;  // define hashmap & size
HASHMAP* create_hashMap() {
    HASHMAP* hashmap = malloc(sizeof(HASHMAP));

    for (int i = 0; i < HASHMAP_SIZE ;i++) {
        hashmap->data[i] = NULL;
    }

    return hashmap;
}

int strlenBetta(const char* str) {
    int i = 0;
    while (str[i] != '\0') {
        // printf("!!%c!!",str[i]);
        i++;
    }
    return i;
}
unsigned int hesh_key(char *name, char *surname, char *year) {
    unsigned int hash = FNV_OFFSET_BASIS;

    while (*name) {
        hash ^= *name++;
        hash *= FNV_PRIME;
    }

    while (*surname) {
        hash ^= *surname++;
        hash *= FNV_PRIME;
    }

    while (*year) {
        hash ^= *year++;
        hash *= FNV_PRIME;
    }

    return hash%HASHMAP_SIZE;
}

unsigned int murmur3(const char *key, int len, unsigned int seed) {
    const unsigned int c1 = 0xcc9e2d51;
    const unsigned int c2 = 0x1b873593;
    const int r1 = 15;
    const int r2 = 13;
    const int m = 5;
    const unsigned int n = 0xe6546b64;
    unsigned int hash = seed;

    const int nblocks = len / 4;
    const unsigned int *blocks = (const unsigned int *) key;
    int i;
    for (i = 0; i < nblocks; i++) {
        unsigned int k = blocks[i];
        k *= c1;
        k = ROTL32(k, r1);
        k *= c2;

        hash ^= k;
        hash = ROTL32(hash, r2);
        hash = hash * m + n;
    }
    const unsigned char *tail = (const unsigned char *) (key + nblocks * 4);
    unsigned int k1 = 0;
    switch (len & 3) {
        case 3:
            k1 ^= tail[2] << 16;
        case 2:
            k1 ^= tail[1] << 8;
        case 1:
            k1 ^= tail[0];
            k1 *= c1;
            k1 = ROTL32(k1, r1);
            k1 *= c2;
            hash ^= k1;
    }
    hash ^= len;
    hash ^= hash >> 16;
    hash *= 0x85ebca6b;
    hash ^= hash >> 13;
    hash *= 0xc2b2ae35;
    hash ^= hash >> 16;

    return hash;
}
unsigned int hesh_info(char *name, char *surname, char *year) {
    unsigned int hash = 0;

    while (*name) {
        hash ^= murmur3(name, strlenBetta(name), 0x9747b28c);
        name++;
    }

    while (*surname) {
        hash ^= murmur3(surname, strlenBetta(surname), 0x5bd1e995);
        surname++;
    }

    while (*year) {
        hash ^= murmur3(year, strlenBetta(year), 0x9ce1f8d7);
        year++;
    }

    return hash;
}

float charToFloat(char* data) {
    float result = 0.0f;
    float decimalFactor = 1.0f;
    int minus;
    minus = 1;
    int pointPart = 0;

    if (*data == '-') {
        minus = -1;
        ++data;
    } else if (*data == '+') {
        ++data;
    }

    while (*data != '\0') {
        if (*data == ',' || *data == '.') {
            pointPart = 1;
            data++;
            continue;
        }
        if (*data < '0' || *data > '9') {
            break; // ak nie cislo
        }
        float digit = (float)(*data - '0'); // convert char to int

        if (!pointPart) {
            result = result * 10 + digit;
        } else {
            decimalFactor *= 0.1f;
            result += digit * decimalFactor;
        }
        data++;
    }
    return result * (float)minus;
}
void replaceDotWithComma(char *str) {
    while (*str != '\0') {
        if (*str == '.') {
            *str = ',';
            break;
        }
        str++;
    }
}


void insertMetod(HASHMAP* hashmap, unsigned int key_hash,unsigned  int key_information,float balance) {
    DATA *insertData = malloc(sizeof(DATA));
    DATA *lastData = hashmap->data[key_hash];
    insertData -> balance = balance;
    insertData -> info_key = key_information;
    insertData -> next = NULL;


    //  printf("/%d/\n",key);
    while (lastData != NULL) {
        if (lastData->info_key == key_information) {
            if (prenos == 1) {
                printf("\ninsert failed");
            } else {
                prenos = 1;
                printf("insert failed");
            }
            return;
        }
        lastData = lastData->next;
    }

    if (hashmap -> data[key_hash] == NULL) {
        hashmap -> data[key_hash] = insertData;
    }else{
        lastData = hashmap -> data[key_hash];
        while (lastData -> next != NULL) {
            lastData = lastData->next;
        }
        lastData -> next = insertData;
    }
}//i-insert
void searchMetod(HASHMAP* hashmap, unsigned int key_hash,unsigned  int key_information) {
    DATA *insertData = hashmap->data[key_hash];

    while (insertData != NULL) {
        if(insertData->info_key == key_information){
            char balanceStr[25];
            sprintf(balanceStr, "%.2f", insertData->balance);
            replaceDotWithComma(balanceStr);

            if (prenos == 1) {
                printf("\n%s", balanceStr);
            } else {
                prenos = 1;
                printf("%s", balanceStr);
            }
            return;
        }
        insertData = insertData->next;
    }

    if (prenos == 1) {
        printf("\nsearch failed");
        return;
    } else {
        prenos = 1;
        printf("search failed");
        return;
    }
}//s-search
void updateMetod(HASHMAP* hashmap, unsigned int key_hash,unsigned int key_information,float newBalance) {
    DATA *insertData = hashmap->data[key_hash];

    while (insertData != NULL) {
        if(insertData->info_key == key_information){
            float check=insertData->balance+newBalance;
            if((check)>=0){
                insertData->balance += newBalance;
                return;
            } else{
                if (prenos == 1) {
                    printf("\nupdate failed");
                    return;
                } else {
                    prenos = 1;
                    printf("update failed");
                    return;
                }
            }
        }
        insertData = insertData->next;
    }

    if (prenos == 1) {
        printf("\nupdate failed");
    } else {
        prenos = 1;
        printf("update failed");
    }
}//u-update
void deleteMetod(HASHMAP* hashmap, unsigned int key_hash,unsigned int key_information) {
    DATA *bufferData = NULL;
    DATA *lastData = hashmap -> data[key_hash];

    while (lastData != NULL) {
        if (lastData->info_key == key_information) {
            if (bufferData == NULL) {
                hashmap -> data[key_hash] = lastData -> next;
            }else {
                bufferData -> next = lastData -> next;
            }
            free(lastData);
            return;
        }
        bufferData = lastData;
        lastData = lastData->next;
    }

    if (prenos == 1) {
        printf("\ndelete failed");
    } else {
        prenos = 1;
        printf("delete failed");
    }
}//d-delete


int main() {
    char line[50];
    HASHMAP* hashmap = create_hashMap();
    char buffName [16];
    char buffSurname [16];
    char buffYear [12];
    char buffBalance[16];
    float balance;

    while (fgets(line, sizeof(line), stdin) != NULL) {
        char c;
        sscanf(line, "%c", &c);

        switch (c) {
            case 'i':
                if (sscanf(line, "%*c %s %s %s %[^\n]", buffName, buffSurname, buffYear, buffBalance) == 4) {
                    float balance = charToFloat(buffBalance);

                    insertMetod(hashmap, hesh_key(buffName,buffSurname,buffYear),hesh_info(buffName,buffSurname,buffYear),balance);
                    //  printf("\n!!%d!!\n",hesh_key(buffName,buffSurname,buffYear));
                }else {
                    if (prenos == 1) {
                        printf("\ninsert failed");
                    } else {
                        prenos = 1;
                        printf("insert failed");
                    }
                }
                break;
            case 's':
                if(sscanf(line,"%*c %s %s %s %s",buffName,buffSurname,buffYear,buffBalance)==3) {

                    searchMetod(hashmap, hesh_key(buffName,buffSurname,buffYear),hesh_info(buffName,buffSurname,buffYear));
                }else {
                    if (prenos == 1) {
                        printf("\nsearch failed");
                    } else {
                        prenos = 1;
                        printf("search failed");
                    }
                }
                break;
            case 'u':
                if(sscanf(line,"%*c %s %s %s %[^\n]",buffName,buffSurname,buffYear,buffBalance)==4) {
                    float balance = charToFloat(buffBalance);

                    updateMetod(hashmap, hesh_key(buffName,buffSurname,buffYear),hesh_info(buffName,buffSurname,buffYear),balance);
                }else {
                    if (prenos == 1) {
                        printf("\nupdate failed");
                    } else {
                        prenos = 1;
                        printf("update failed");
                    }
                }
                break;
            case 'd':
                if(sscanf(line,"%*c %s %s %s %s",buffName,buffSurname,buffYear,buffBalance)==3) {
                    deleteMetod(hashmap, hesh_key(buffName,buffSurname,buffYear),hesh_info(buffName,buffSurname,buffYear));
                }else {
                    if (prenos == 1) {
                        printf("\ndelete failed");
                    } else {
                        prenos = 1;
                        printf("delete failed");
                    }
                }
                break;
            default:
                printf("Error in switch case\n");
                free(hashmap);
                return 1;
        }
    }
    for (int i = 0; i < HASHMAP_SIZE; i++) {
        DATA *current = hashmap->data[i];
        while (current != NULL) {
            DATA *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(hashmap);
    return 0;
} // main function