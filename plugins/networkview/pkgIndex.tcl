# Tcl package index file, version 1.1
# This file is generated by the "pkg_mkIndex" command
# and sourced either when an application starts up or
# by a "package unknown" script.  It invokes the
# "package ifneeded" command to set up package-related
# information so that packages will be loaded automatically
# in response to "package require" commands.  When this
# script is sourced, the variable $dir must contain the
# full path name of this file's directory.

package ifneeded networkview 1.2 [list source [file join $dir networkView.tcl]]\n[list source [file join $dir networkViewGui.tcl]]\n[list source [file join $dir suboptimalPaths.tcl]]\n[list source [file join $dir communityNetwork.tcl]]\n[list source [file join $dir networkSetup.tcl]]\n[list source [file join $dir adjacencyMatrix.tcl]]
