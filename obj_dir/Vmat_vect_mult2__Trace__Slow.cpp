// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vmat_vect_mult2__Syms.h"


//======================

void Vmat_vect_mult2::trace (VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback (&Vmat_vect_mult2::traceInit, &Vmat_vect_mult2::traceFull, &Vmat_vect_mult2::traceChg, this);
}
void Vmat_vect_mult2::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vmat_vect_mult2* t=(Vmat_vect_mult2*)userthis;
    Vmat_vect_mult2__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) vl_fatal(__FILE__,__LINE__,__FILE__,"Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    vcdp->scopeEscape(' ');
    t->traceInitThis (vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vmat_vect_mult2::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vmat_vect_mult2* t=(Vmat_vect_mult2*)userthis;
    Vmat_vect_mult2__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    t->traceFullThis (vlSymsp, vcdp, code);
}

//======================


void Vmat_vect_mult2::traceInitThis(Vmat_vect_mult2__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vmat_vect_mult2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name()); // Setup signal names
    // Body
    {
	vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vmat_vect_mult2::traceFullThis(Vmat_vect_mult2__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vmat_vect_mult2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vmat_vect_mult2::traceInitThis__1(Vmat_vect_mult2__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vmat_vect_mult2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->declBit  (c+11,"aclk",-1);
	vcdp->declBit  (c+12,"areset",-1);
	vcdp->declBus  (c+13,"inp_vect",-1,7,0);
	vcdp->declBit  (c+14,"inp_vect_valid",-1);
	vcdp->declBit  (c+15,"inp_vect_rdy",-1);
	vcdp->declBus  (c+16,"s_axis_tdata",-1,7,0);
	vcdp->declBit  (c+17,"s_axis_tvalid",-1);
	vcdp->declBit  (c+18,"s_axis_tlast",-1);
	vcdp->declBit  (c+19,"s_axis_tready",-1);
	vcdp->declBus  (c+20,"m_axis_tdata",-1,17,0);
	vcdp->declBit  (c+21,"m_axis_tvalid",-1);
	vcdp->declBit  (c+22,"m_axis_tlast",-1);
	vcdp->declBit  (c+23,"m_axis_tready",-1);
	vcdp->declBit  (c+11,"mat_vect_mult2 aclk",-1);
	vcdp->declBit  (c+12,"mat_vect_mult2 areset",-1);
	vcdp->declBus  (c+13,"mat_vect_mult2 inp_vect",-1,7,0);
	vcdp->declBit  (c+14,"mat_vect_mult2 inp_vect_valid",-1);
	vcdp->declBit  (c+15,"mat_vect_mult2 inp_vect_rdy",-1);
	vcdp->declBus  (c+16,"mat_vect_mult2 s_axis_tdata",-1,7,0);
	vcdp->declBit  (c+17,"mat_vect_mult2 s_axis_tvalid",-1);
	vcdp->declBit  (c+18,"mat_vect_mult2 s_axis_tlast",-1);
	vcdp->declBit  (c+19,"mat_vect_mult2 s_axis_tready",-1);
	vcdp->declBus  (c+20,"mat_vect_mult2 m_axis_tdata",-1,17,0);
	vcdp->declBit  (c+21,"mat_vect_mult2 m_axis_tvalid",-1);
	vcdp->declBit  (c+22,"mat_vect_mult2 m_axis_tlast",-1);
	vcdp->declBit  (c+23,"mat_vect_mult2 m_axis_tready",-1);
	vcdp->declBus  (c+5,"mat_vect_mult2 count",-1,1,0);
	vcdp->declBus  (c+6,"mat_vect_mult2 slice",-1,1,0);
	{int i; for (i=0; i<4; i++) {
		vcdp->declBus  (c+1+i*1,"mat_vect_mult2 inp_vect_lat",(i+0),7,0);}}
	{int i; for (i=0; i<4; i++) {
		vcdp->declBus  (c+7+i*1,"mat_vect_mult2 inp_vect_reg",(i+0),7,0);}}
	// Tracing: mat_vect_mult2 i // Ignored: Verilator trace_off at mat_vect_mult2.v:38
    }
}

void Vmat_vect_mult2::traceFullThis__1(Vmat_vect_mult2__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vmat_vect_mult2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->fullBus  (c+1,(vlTOPp->mat_vect_mult2__DOT__inp_vect_lat[0]),8);
	vcdp->fullBus  (c+2,(vlTOPp->mat_vect_mult2__DOT__inp_vect_lat[1]),8);
	vcdp->fullBus  (c+3,(vlTOPp->mat_vect_mult2__DOT__inp_vect_lat[2]),8);
	vcdp->fullBus  (c+4,(vlTOPp->mat_vect_mult2__DOT__inp_vect_lat[3]),8);
	vcdp->fullBus  (c+5,(vlTOPp->mat_vect_mult2__DOT__count),2);
	vcdp->fullBus  (c+6,(vlTOPp->mat_vect_mult2__DOT__slice),2);
	vcdp->fullBus  (c+7,(vlTOPp->mat_vect_mult2__DOT__inp_vect_reg[0]),8);
	vcdp->fullBus  (c+8,(vlTOPp->mat_vect_mult2__DOT__inp_vect_reg[1]),8);
	vcdp->fullBus  (c+9,(vlTOPp->mat_vect_mult2__DOT__inp_vect_reg[2]),8);
	vcdp->fullBus  (c+10,(vlTOPp->mat_vect_mult2__DOT__inp_vect_reg[3]),8);
	vcdp->fullBit  (c+11,(vlTOPp->aclk));
	vcdp->fullBit  (c+12,(vlTOPp->areset));
	vcdp->fullBus  (c+13,(vlTOPp->inp_vect),8);
	vcdp->fullBit  (c+14,(vlTOPp->inp_vect_valid));
	vcdp->fullBit  (c+15,(vlTOPp->inp_vect_rdy));
	vcdp->fullBus  (c+16,(vlTOPp->s_axis_tdata),8);
	vcdp->fullBit  (c+17,(vlTOPp->s_axis_tvalid));
	vcdp->fullBit  (c+18,(vlTOPp->s_axis_tlast));
	vcdp->fullBit  (c+19,(vlTOPp->s_axis_tready));
	vcdp->fullBus  (c+20,(vlTOPp->m_axis_tdata),18);
	vcdp->fullBit  (c+21,(vlTOPp->m_axis_tvalid));
	vcdp->fullBit  (c+22,(vlTOPp->m_axis_tlast));
	vcdp->fullBit  (c+23,(vlTOPp->m_axis_tready));
    }
}
