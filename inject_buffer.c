#include <string.h>
#include "inject_buffer.h"

void inject_buffer_init(struct inject_buffer *ib) {
  ib->num_entries = 0;
  ib->buf[0] = 0;
  ib->entries[0] = 0;
}

void inject_buffer_add(struct inject_buffer *ib, char *entry) {

  int len = strlen(ib->buf);
  char *new_entry = &ib->buf[len + 1];

  ib->entries[ib->num_entries++] = new_entry;
  ib->entries[ib->num_entries] = 0;
  strcpy(new_entry, entry);

}
