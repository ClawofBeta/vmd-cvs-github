/***************************************************************************
 *cr
 *cr            (C) Copyright 1995-2011 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/

/***************************************************************************
 * RCS INFORMATION:
 *
 *      $RCSfile: vmdmain.C,v $
 *      $Author: johns $        $Locker:  $             $State: Exp $
 *      $Revision: 1.10 $       $Date: 2012/10/17 04:07:16 $
 *
 ***************************************************************************
 * DESCRIPTION:
 *
 * Main program.
 *
 ***************************************************************************/
#include "vmd.h"

#if defined(ANDROID)
int VMDmain(int argc, char **argv) {
#else
int main(int argc, char **argv) {
#endif
  if (!VMDinitialize(&argc, &argv)) {
    return 0;
  }

  const char *displayTypeName = VMDgetDisplayTypeName();
  int displayLoc[2], displaySize[2];
  VMDgetDisplayFrame(displayLoc, displaySize);

  VMDApp *app = new VMDApp(argc, argv);

  if (!app->VMDinit(argc, argv, displayTypeName, displayLoc, displaySize)) {
    delete app;
    return 1;
  }

  // read various application defaults
  VMDreadInit(app);

  // read user-defined startup files
  VMDreadStartup(app);

  // main event loop
  do {
    // If we knew that there were no embedded python interpreter, we could
    // process Tcl events here, rather than within the VMD instance. 
#ifdef VMDTCL
    // Loop on the Tcl event notifier
    // while (Tcl_DoOneEvent(TCL_DONT_WAIT));
#endif

    // handle Fltk events
    VMDupdateFltk();

#if 0
    // take over the console
    if (vmd_check_stdin()) {
      app->process_console();
    }
#endif

  } while(app->VMDupdate(VMD_CHECK_EVENTS));

  // end of program
  delete app;
  VMDshutdown();

  return 0;
}

