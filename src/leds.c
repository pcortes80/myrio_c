/*
 * FPGA Interface C API example for GCC.
 * Demo for myRIO - 1900
 * Driving User LED0 to LED3
 */

#include "../fpgaInterface/NiFpga_mainFPGA.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
   /* must be called before any other calls */
   printf("Initializing...\n");
   NiFpga_Status status = NiFpga_Initialize();
   
   if (NiFpga_IsNotError(status))
   {
      NiFpga_Session session;
      /* opens a session and downloads the bitstream */
      printf("Opening a session...\n");
      //NiFpga_MergeStatus(&status);
      NiFpga_Open(NiFpga_mainFPGA_Bitfile,
                                        NiFpga_mainFPGA_Signature,
                                        "RIO0",
                                        NiFpga_OpenAttribute_NoRun,
                                        &session);
      if (NiFpga_IsNotError(status))
      {
        /* run the FPGA application */
        printf("Running the FPGA...\n");
        NiFpga_Run(session, 0);
                
        NiFpga_WriteI32(session, NiFpga_mainFPGA_ControlI32_ledsControl, 0);
        printf("LED0=True, LED1=False, LED2=False, LED3=False\n");
        sleep(1);

        NiFpga_WriteI32(session, NiFpga_mainFPGA_ControlI32_ledsControl, 1);
        printf("LED0=False, LED1=True, LED2=False, LED3=False\n");
        sleep(1);

        NiFpga_WriteI32(session, NiFpga_mainFPGA_ControlI32_ledsControl, 2);
        printf("LED0=True, LED1=True, LED2=False, LED3=False\n");
        sleep(1);

        }

        printf("Press <Enter> to stop and quit...");
        getchar();
        /* stop the FPGA loops */
        printf("Stopping the FPGA...\n");
         
        /* close the session now that we're done */
        printf("Closing the session...\n");
        NiFpga_Close(session, 0);
    }
      /* must be called after all other calls */
      printf("Finalizing...\n");
      NiFpga_Finalize();
   
   /* check if anything went wrong */
   if (NiFpga_IsError(status))
   {
      printf("Error %d!\n", status);
      printf("Press <Enter> to quit...\n");
      getchar();
   }
   return status;
}