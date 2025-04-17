#ifndef _hashtable_h_
#define _hashtable_h_




unsigned int GetHashPosition(char *s);
ADMINHASH *InitHash(int length);
ADMINNODE *HashSearch(ADMINHASH *hash, char name[10]);
int Hashinsert(ADMINHASH *hash, ADMINOB *node);
int Hashdelete(ADMINHASH *hash, char name[10]);
void hashclean(ADMINHASH **phash);
void hashdestroy(ADMINHASH **phash);
void hashinput(ADMINHASH *hash);
void hashoutput(ADMINHASH *hash);
void output(ADMINHASH *hash, int page, int *state);


#endif

