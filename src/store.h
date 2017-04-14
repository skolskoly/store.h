#ifndef STORE_H
#define STORE_H

#ifndef N_VARIABLES
#define N_VARIABLES 100
#endif

void * vars [N_VARIABLES];
char * names[N_VARIABLES];
size_t sizes[N_VARIABLES];

int idx = 0;

void registerVariable(void * data, char * name, size_t size)
{
	if( idx >= N_VARIABLES )
	{
		printf("Variable registery out of memory!");
		return;
	}
	
	vars[idx] = data;
	names[idx] = name;
	sizes[idx] = size;
	idx++;
	
}

void saveToDisk(void * data, char * name, size_t size)
{
	FILE * fp = fopen(name, "w+");
	char * ch = (char *) data;
	
	while(size-- > 0)
		fputc(*(ch++), fp);
	fclose(fp);
}

void loadFromDisk(void * data, char * name, size_t size)
{
	FILE * fp = fopen(name, "r+");
	if(!fp)
		return;
		
	char * ch = (char *) data;
	
	while(size-- > 0)
		*(ch++) = fgetc(fp);
	fclose(fp);
}

void saveAll()
{
	for(int i = 0; i < idx; i++)
		saveToDisk(vars[i], names[i], sizes[i]);
}

void loadAll()
{
	for(int i = 0; i < idx; i++)
		loadFromDisk(vars[i], names[i], sizes[i]);
}

#define REG(X) registerVariable((void *) &X, #X, sizeof(X))
#define SAVE(X) saveToDisk((void *) &X, #X, sizeof(X))
#define LOAD(X) loadFromDisk((void *) &X, #X, sizeof(X))


#endif
