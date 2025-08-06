#ifndef SERIAL_PORTS_H
#define SERIAL_PORTS_H

#include <cvidef.h>

#ifdef __cplusplus
extern "C" {
#endif

	/**
	 * Enumerate all serial ports (“COM1”, “COM2”, …).
	 * Returns a NULL-terminated array of malloc’d strings;
	 * caller must free via free_serial_ports().
	 */
	extern char DLLIMPORT ** enum_serial_ports(void);
	extern void DLLIMPORT  free_serial_ports(char **ports);

#ifdef __cplusplus
}
#endif

#endif  /* SERIAL_PORTS_H */
