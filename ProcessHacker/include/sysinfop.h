#ifndef SYSINFOP_H
#define SYSINFOP_H

#define PH_SYSINFO_FADE_WIDTH 140
#define PH_SYSINFO_PANEL_PADDING 3
#define PH_SYSINFO_WINDOW_PADDING 13
#define PH_SYSINFO_GRAPH_PADDING 9
#define PH_SYSINFO_SMALL_GRAPH_WIDTH 48
#define PH_SYSINFO_SMALL_GRAPH_PADDING 5
#define PH_SYSINFO_SEPARATOR_WIDTH 2

#define PH_SYSINFO_CPU_PADDING 5

#define SI_MSG_SYSINFO_FIRST (WM_APP + 150)
#define SI_MSG_SYSINFO_ACTIVATE (WM_APP + 150)
#define SI_MSG_SYSINFO_UPDATE (WM_APP + 151)
#define SI_MSG_SYSINFO_LAST (WM_APP + 151)

// Thread & window

NTSTATUS PhSipSysInfoThreadStart(
    __in PVOID Parameter
    );

INT_PTR CALLBACK PhSipSysInfoDialogProc(
    __in HWND hwndDlg,
    __in UINT uMsg,
    __in WPARAM wParam,
    __in LPARAM lParam
    );

// Event handlers

VOID PhSipOnInitDialog(
    VOID
    );

VOID PhSipOnDestroy(
    VOID
    );

VOID PhSipOnShowWindow(
    __in BOOLEAN Showing,
    __in ULONG State
    );

VOID PhSipOnSize(
    VOID
    );

VOID PhSipOnSizing(
    __in ULONG Edge,
    __in PRECT DragRectangle
    );

VOID PhSipOnCommand(
    __in ULONG Id,
    __in ULONG Code
    );

BOOLEAN PhSipOnNotify(
    __in NMHDR *Header,
    __out LRESULT *Result
    );

BOOLEAN PhSipOnDrawItem(
    __in ULONG_PTR Id,
    __in DRAWITEMSTRUCT *DrawItemStruct
    );

VOID PhSipOnUserMessage(
    __in ULONG Message,
    __in ULONG_PTR WParam,
    __in ULONG_PTR LParam
    );

// Framework

VOID PhSipInitializeParameters(
    VOID
    );

VOID PhSipDeleteParameters(
    VOID
    );

PPH_SYSINFO_SECTION PhSipCreateSection(
    __in PPH_SYSINFO_SECTION Template
    );

VOID PhSipDestroySection(
    __in PPH_SYSINFO_SECTION Section
    );

PPH_SYSINFO_SECTION PhSipCreateInternalSection(
    __in PWSTR Name,
    __in ULONG Flags,
    __in PPH_SYSINFO_SECTION_CALLBACK Callback
    );

VOID PhSipDrawRestoreSummaryPanel(
    __in HDC hdc,
    __in PRECT Rect
    );

VOID PhSipDrawSeparator(
    __in HDC hdc,
    __in PRECT Rect
    );

VOID PhSipDrawPanel(
    __in PPH_SYSINFO_SECTION Section,
    __in HDC hdc,
    __in PRECT Rect
    );

VOID PhSipDefaultDrawPanel(
    __in PPH_SYSINFO_SECTION Section,
    __in PPH_SYSINFO_DRAW_PANEL DrawPanel
    );

VOID PhSipLayoutSummaryView(
    VOID
    );

VOID PhSipLayoutSectionView(
    VOID
    );

VOID PhSipEnterSectionView(
    __in PPH_SYSINFO_SECTION NewSection
    );

VOID PhSipRestoreSummaryView(
    VOID
    );

HWND PhSipDefaultCreateDialog(
    __in PVOID Instance,
    __in PWSTR Template,
    __in DLGPROC DialogProc
    );

VOID PhSipCreateSectionDialog(
    __in PPH_SYSINFO_SECTION Section
    );

// Misc.

VOID PhSipSetAlwaysOnTop(
    VOID
    );

VOID NTAPI PhSipSysInfoUpdateHandler(
    __in_opt PVOID Parameter,
    __in_opt PVOID Context
    );

PPH_STRING PhSipFormatSizeWithPrecision(
    __in ULONG64 Size,
    __in USHORT Precision
    );

// CPU section

BOOLEAN PhSipCpuSectionCallback(
    __in PPH_SYSINFO_SECTION Section,
    __in PH_SYSINFO_SECTION_MESSAGE Message,
    __in_opt PVOID Parameter1,
    __in_opt PVOID Parameter2
    );

INT_PTR CALLBACK PhSipCpuDialogProc(
    __in HWND hwndDlg,
    __in UINT uMsg,
    __in WPARAM wParam,
    __in LPARAM lParam
    );

INT_PTR CALLBACK PhSipCpuPanelDialogProc(
    __in HWND hwndDlg,
    __in UINT uMsg,
    __in WPARAM wParam,
    __in LPARAM lParam
    );

VOID PhSipCreateCpuGraphs(
    VOID
    );

VOID PhSipLayoutCpuGraphs(
    VOID
    );

VOID PhSipSetOneGraphPerCpu(
    VOID
    );

VOID PhSipNotifyCpuGraph(
    __in ULONG Index,
    __in NMHDR *Header
    );

VOID PhSipUpdateCpuGraphs(
    VOID
    );

VOID PhSipUpdateCpuPanel(
    VOID
    );

PPH_PROCESS_RECORD PhSipReferenceMaxCpuRecord(
    __in LONG Index
    );

PPH_STRING PhSipGetMaxCpuString(
    __in LONG Index
    );

VOID PhSipGetCpuBrandString(
    __out_ecount(49) PWSTR BrandString
    );

// Memory section

BOOLEAN PhSipMemorySectionCallback(
    __in PPH_SYSINFO_SECTION Section,
    __in PH_SYSINFO_SECTION_MESSAGE Message,
    __in_opt PVOID Parameter1,
    __in_opt PVOID Parameter2
    );

// I/O section

BOOLEAN PhSipIoSectionCallback(
    __in PPH_SYSINFO_SECTION Section,
    __in PH_SYSINFO_SECTION_MESSAGE Message,
    __in_opt PVOID Parameter1,
    __in_opt PVOID Parameter2
    );

PPH_PROCESS_RECORD PhSipReferenceMaxIoRecord(
    __in LONG Index
    );

PPH_STRING PhSipGetMaxIoString(
    __in LONG Index
    );

#endif