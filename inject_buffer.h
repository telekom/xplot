#ifndef INJECT_BUFFER_H
#define INJECT_BUFFER_H

#define INJECT_BUFFER_SIZE 2048
#define INJECT_BUFFER_ENTRIES 64

struct inject_buffer {

  char buf[INJECT_BUFFER_SIZE];
  char *entries[INJECT_BUFFER_ENTRIES];
  int num_entries;

};


void inject_buffer_init(struct inject_buffer *ib);
void inject_buffer_add(struct inject_buffer *ib, char *entry);


#endif
