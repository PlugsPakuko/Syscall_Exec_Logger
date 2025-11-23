#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include "exec_log_kmod.h"

void rb_init(void);
void rb_cleanup(void);
void rb_push(const struct exec_event *ev);
int  rb_snapshot(struct exec_event *out, int max);

#endif /* RING_BUFFER_H */
