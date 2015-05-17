#ifndef CPUTEMP_H
#define CPUTEMP_H

#define CPUTEMP_OK                 0
#define CPUTEMP_UNSUPPORTED_CPU    1
#define CPUTEMP_NO_DRIVER          2
#define CPUTEMP_INVALID_ARGUMENT   3
#define CPUTEMP_AFFINITY_FAILED    4
#define CPUTEMP_INVALID_VALUE      5

#define CPUTEMP_FL_WAKEUP          1

typedef struct _CPUTEMP {
  unsigned long    cbSize;      // Size of structure.
  unsigned long    cCPU;        // Numer of CPUs installed.
  unsigned long    ulMaxTemp;   // Maximum temerature on CPU.
  unsigned long    ulTimestamp; // Last alTemp update timestamp [msec].
  long             alTemp[64];  // Temperatures for each CPU (core), value -1
                                // means that CPU is OFFLINEd and the data was
                                // not obtained.
} CPUTEMP, *PCPUTEMP;

void APIENTRY cputempSetFlags(unsigned long ulNewFlags);
int APIENTRY cputempQuery(PCPUTEMP pstCPUTemp);

#endif // CPUTEMP_H
