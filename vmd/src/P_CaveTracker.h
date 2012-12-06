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
 *	$RCSfile: P_CaveTracker.h,v $
 *	$Author: johns $	$Locker:  $		$State: Exp $
 *	$Revision: 1.18 $	$Date: 2010/12/16 04:08:29 $
 *
 ***************************************************************************
 * DESCRIPTION:
 * This is Paul's new Tracker code -- pgrayson@ks.uiuc.edu
 *
 * Representation of the Tracker in the CAVE.
 *
 ***************************************************************************/

/// VMDTracker subclass that interfaces to the CAVE wand
class CaveTracker : public VMDTracker {
 private:
   int caveTrackerNum;

 protected:
  int do_start(const SensorConfig *config);

 public:
  CaveTracker()
  : caveTrackerNum(1) {}

  const char *device_name() const { return "cavetracker"; }
  virtual VMDTracker *clone() { return new CaveTracker; } 

  inline virtual int alive() { return 1; }
  virtual void update();
};

