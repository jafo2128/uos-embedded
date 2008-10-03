/*
 * Testing SLIP.
 */
#include <runtime/lib.h>
#include <kernel/uos.h>
#include <mem/mem.h>
#include <buf/buf.h>
#include <uart/slip.h>

/*
 * Установлена микросхема 16kx8 - имеем 60 килобайт памяти.
 */
#define RAM_START	0x1000
#define RAM_END		0xffff

ARRAY (task, 0x200);
mem_pool_t pool;
slip_t slip;

void hello (void *data)
{
	buf_t *p;

	debug_printf ("\n*** Testing SLIP on UART 1 ***\n");
	lock_take (&slip.netif.lock);
	for (;;) {
		lock_wait (&slip.netif.lock);
		p = netif_input (&slip.netif);
		if (p) {
			buf_print_ip (p);
#if 1
			netif_output (&slip.netif, p, 0, 0);
#else
			buf_free (p);
#endif
		}
	}
}

void uos_init (void)
{
/* Baud 19200. */
outb (((int) (KHZ * 1000L / 19200) + 8) / 16 - 1, UBRR);

	/* Разрешаем внешнюю память: порты A - адрес/данные, C - адрес. */
	setb (SRE, MCUCR);
	mem_init (&pool, RAM_START, RAM_END);

	slip_init (&slip, 0, "slip0", 80, &pool, KHZ, 38400);
	task_create (hello, 0, "hello", 1, task, sizeof (task));
}
