/*
 * Copyright (C) 2011-2021 Intel Corporation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 *   * Neither the name of Intel Corporation nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef _SE_EVENT_H_
#define _SE_EVENT_H_

# include <stdlib.h>
# include <unistd.h>
# include <sys/syscall.h>
typedef void * se_handle_t;

#include "sgx_defs.h"
#include "se_types.h"

#define SE_MUTEX_SUCCESS    0x0
#define SE_MUTEX_INVALID    0x1
#define SE_MUTEX_ERROR_WAKE 0x2
#define SE_MUTEX_ERROR_WAIT 0x3
#define SE_MUTEX_TIMEOUT    0x4

#ifdef __cplusplus
extern "C" {
#endif

se_handle_t SGXAPI se_event_init(void);
void SGXAPI se_event_destroy(se_handle_t);

int SGXAPI se_event_wait(se_handle_t);
int SGXAPI se_event_wait_timeout(se_handle_t se_event, uint64_t timeout);
int SGXAPI se_event_wait_deadline(se_handle_t se_event, unsigned long long dl_sec, long dl_nsec);
int SGXAPI se_event_wake(se_handle_t);

#ifdef __cplusplus
}
#endif

#endif
