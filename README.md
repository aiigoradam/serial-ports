Windows DLL for listing available serial (COM) ports.  

Provides two C functions:  
- `char **enum_serial_ports(void)` – returns a NULL-terminated array of malloc’d strings with port names (e.g. `"COM1"`, `"COM3"`, …).  
- `void free_serial_ports(char **ports)` – frees the returned array and its strings.  

Drop `serialports.dll` and `serialports.h` into any windows project.  
