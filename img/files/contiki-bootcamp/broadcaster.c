/*
 * Copyright (c) 2012, CSIRO.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */


/*
  broadcaster.c
  Simple program that periodically toggles the LEDs on a Tmote Sky mote, and broadcasts
  a simple packet.
  This file is used in demonstrating some features of COOJA and MSPSim.

  also available at http://pastebin.com/xCn3PFx5
  
  Author: Marcus Lundén, CSIRO, QCAT, ASL
  email:  marcus.lunden@csiro.au
*/



#include <stdio.h>
#include <stdlib.h>
#include "contiki.h"
#include "contiki-net.h"
#include "shell.h"
#include "serial-shell.h"
#include "dev/leds.h"
#include "random.h"

#define STRING_MAX_LEN  20
static uint8_t msg_str[STRING_MAX_LEN];
static uint8_t cooja_debug_str[STRING_MAX_LEN];
static int8_t msg_str_len = 0;
static uint16_t count = 0;

/* -------------------------------------------------------------------------- */
/* Broadcast receive callback. */

static void
broadcast_recv(struct broadcast_conn *c, const rimeaddr_t *f){
  unsigned char *msg = packetbuf_dataptr();
  
  printf("Broadcast received from: %u.%u\n", f->u8[0], f->u8[1]);
  printf("Message:'%s'\n", msg);
}
/* -------------------------------------------------------------------------- */
PROCESS(startup_process, "Blink Process");
AUTOSTART_PROCESSES(&startup_process);
/* -------------------------------------------------------------------------- */
/* This process... 
*/
static struct etimer ucet;
static struct broadcast_conn bc;
static struct broadcast_callbacks cb = {broadcast_recv, NULL};

PROCESS_THREAD(startup_process, ev, data) {
  PROCESS_POLLHANDLER();
  PROCESS_EXITHANDLER();
  PROCESS_BEGIN();
  serial_shell_init();
  shell_sky_init();
  shell_text_init();
  shell_file_init();
  shell_time_init();
  shell_ps_init();
  shell_coffee_init();
  broadcast_open(&bc, 2012, &cb);
  count = random_rand();
  
  while (1) {
    leds_toggle(LEDS_RED | LEDS_GREEN | LEDS_BLUE);
    count++;
    msg_str_len = snprintf(msg_str, 20, "Hello nr: %u", count) + 1;   // snprintf doesn't count the trailing \0, hence +1
    // The cooja_debug_str vector can be monitored in COOJA. This is just an example,
    // in this case it would actually be more efficient and better to just use 'Variable watcher'.
    snprintf(cooja_debug_str, 20, "DEBUG: now %u", count);

    if (msg_str_len > 0) {
      packetbuf_copyfrom(&msg_str, (uint8_t)msg_str_len);
      broadcast_send(&bc);
      printf("Sent '%s'\n", msg_str);
    } else {
      printf("Failure to copy string (increase string buffer size)\n");
    }
    etimer_set(&ucet, CLOCK_SECOND*2);
    PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&ucet));
  }  
  PROCESS_END();
}
 
 

