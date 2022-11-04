//
//
// tf-rom - resident CLI command test for 'cpuspeed'
// Copyright (c) Erik Hemming
//
// This software is licensed under MIT ; see LICENSE file
//
//

#include <proto/dos.h>
#include <proto/exec.h>

#include <exec/nodes.h>
#include <exec/resident.h>

void* Init();
int Run();
extern int end;

int Start()
{
    return Run();
}

__section(CODE) struct Resident romtag =
{
    .rt_MatchWord   = RTC_MATCHWORD,
    .rt_MatchTag    = &romtag,
    .rt_EndSkip     = &end,
    .rt_Flags       = RTF_AFTERDOS,
    .rt_Version     = 1,
    .rt_Type        = NT_UNKNOWN,
    .rt_Pri         = 0,
    .rt_Name        = "tf-rom",
    .rt_IdString    = "tf-rom 1.0 (4.11.2022)\n\r",
    .rt_Init        = (APTR)Init
};
