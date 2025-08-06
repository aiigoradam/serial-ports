#include "serial_ports.h"
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char DLLEXPORT **enum_serial_ports(void)
{
	DWORD bufSize = 65536;
	char *buf = malloc(bufSize);
	if (!buf)
		return NULL;

	if (QueryDosDeviceA(NULL, buf, bufSize) == 0)
	{
		free(buf);
		return NULL;
	}

	size_t cap = 8, count = 0;
	char **ports = malloc(cap * sizeof *ports);

	for (char *p = buf; *p; p += strlen(p) + 1)
	{
		if (strnicmp(p, "COM", 3) == 0)
		{
			int num = atoi(p + 3);
			if (num > 0)
			{
				char name[16];
				int n = snprintf(name, sizeof(name), "COM%d", num);

				char *s = malloc(n + 1);
				memcpy(s, name, n + 1);

				if (count + 1 > cap)
				{
					cap *= 2;
					ports = realloc(ports, cap * sizeof *ports);
				}
				ports[count++] = s;
			}
		}
	}

	free(buf);

	ports = realloc(ports, (count + 1) * sizeof *ports);
	ports[count] = NULL;
	return ports;
}

void DLLEXPORT free_serial_ports(char **ports)
{
	if (!ports)
		return;
	for (char **p = ports; *p; ++p)
		free(*p);
	free(ports);
}
