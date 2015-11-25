#ifndef __RECORD_SOUND__#define __RECORD_SOUND__#include <SoundInput.h>//So we can pass our A5 and other info to our PBWrite completion routinestypedef struct myRecordingParamBlockRec {	ParamBlockRec			pb;	long					myA5;	Boolean					pbInUse,							lastWrite;} myRecordingParamBlockRec, *myRecordingParmBlkPtr;//Keep track of the info needed to recordtypedef struct {	long					sanitycheck;	OSErr					theErr;		//last error returned by SPBRecord or PBWrite	SPBPtr					recordRec;	myRecordingParmBlkPtr	pb0,							pb1;	Ptr						recBuffer0,							recBuffer1,							resampledBuf0,							resampledBuf1;	SoundConverter			sc;	SoundComponentData		inputFormat,							outputFormat;	Fixed					sampleRate;	OSType					compression;	unsigned long			totalBytes,							inputFrames;	long					myA5,							devBuffer,							parID,							soundRefNum,							initialOffset;	short					whichBuffer,							fileRefNum,							volRefNum,							numChannels,							sampleSize,							AGC;	Str255					nameString;} Vars, *VarsPtr;OSErr			PrepairToRecordToDisk	(VarsPtr myVars, short refNum, short sampleSize, UnsignedFixed sampleRate, short numChannels, OSType compression, short AGC);OSErr			RecordToDisk 			(VarsPtr myVars);pascal void		MyRecComp				(SPBPtr inParamPtr);OSErr			FinishRecording 		(VarsPtr myVars);#if GENERATINGCFMpascal void		MyPB0WriteComp			(myRecordingParmBlkPtr passedPB);pascal void		MyPB1WriteComp			(myRecordingParmBlkPtr passedPB);#else pascal void		MyPB0WriteComp			(myRecordingParmBlkPtr passedPB:__a0);pascal void		MyPB1WriteComp			(myRecordingParmBlkPtr passedPB:__a0);#endif#endif