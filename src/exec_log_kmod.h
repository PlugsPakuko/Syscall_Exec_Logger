#ifndef EXEC_LOG_KMOD_H
#define EXEC_LOG_KMOD_H

#include <linux/types.h>

#define EXEC_LOG_MAX_EVENTS   64
#define EXEC_LOG_COMM_LEN     16
#define EXEC_LOG_PATH_LEN     80

struct exec_event {
    uid_t uid;
    gid_t gid;
    pid_t pid;
    char  comm[EXEC_LOG_COMM_LEN];
    char  path[EXEC_LOG_PATH_LEN];
    u64   ts_ns;   /* timestamp in nanoseconds */
};

/* ring_buffer.c */
void rb_init(void);
void rb_cleanup(void);
void rb_push(const struct exec_event *ev);
int  rb_snapshot(struct exec_event *out, int max);

/* trace_handler.c */
int  register_exec_trace_handler(void);
void unregister_exec_trace_handler(void);

/* proc_interface.c */
int  create_exec_log_proc(void);
void remove_exec_log_proc(void);

#endif /* EXEC_LOG_KMOD_H */