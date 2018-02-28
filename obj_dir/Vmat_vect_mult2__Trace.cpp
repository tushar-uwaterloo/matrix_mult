// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vmat_vect_mult2__Syms.h"


//======================

void Vmat_vect_mult2::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vmat_vect_mult2* t=(Vmat_vect_mult2*)userthis;
    Vmat_vect_mult2__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
	t->traceChgThis (vlSymsp, vcdp, code);
    }
}

//======================


void Vmat_vect_mult2::traceChgThis(Vmat_vect_mult2__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vmat_vect_mult2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 2U))))) {
	    vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
	}
	vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vmat_vect_mult2::traceChgThis__2(Vmat_vect_mult2__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vmat_vect_mult2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+1,(vlTOPp->mat_vect_mult2__DOT__inp_vect_lat[0]),8);
	vcdp->chgBus  (c+2,(vlTOPp->mat_vect_mult2__DOT__inp_vect_lat[1]),8);
	vcdp->chgBus  (c+3,(vlTOPp->mat_vect_mult2__DOT__inp_vect_lat[2]),8);
	vcdp->chgBus  (c+4,(vlTOPp->mat_vect_mult2__DOT__inp_vect_lat[3]),8);
    }
}

void Vmat_vect_mult2::traceChgThis__3(Vmat_vect_mult2__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vmat_vect_mult2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+5,(vlTOPp->mat_vect_mult2__DOT__count),2);
	vcdp->chgBus  (c+6,(vlTOPp->mat_vect_mult2__DOT__slice),2);
	vcdp->chgBus  (c+7,(vlTOPp->mat_vect_mult2__DOT__inp_vect_reg[0]),8);
	vcdp->chgBus  (c+8,(vlTOPp->mat_vect_mult2__DOT__inp_vect_reg[1]),8);
	vcdp->chgBus  (c+9,(vlTOPp->mat_vect_mult2__DOT__inp_vect_reg[2]),8);
	vcdp->chgBus  (c+10,(vlTOPp->mat_vect_mult2__DOT__inp_vect_reg[3]),8);
    }
}

void Vmat_vect_mult2::traceChgThis__4(Vmat_vect_mult2__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vmat_vect_mult2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+11,(vlTOPp->aclk));
	vcdp->chgBit  (c+12,(vlTOPp->areset));
	vcdp->chgBus  (c+13,(vlTOPp->inp_vect),8);
	vcdp->chgBit  (c+14,(vlTOPp->inp_vect_valid));
	vcdp->chgBit  (c+15,(vlTOPp->inp_vect_rdy));
	vcdp->chgBus  (c+16,(vlTOPp->s_axis_tdata),8);
	vcdp->chgBit  (c+17,(vlTOPp->s_axis_tvalid));
	vcdp->chgBit  (c+18,(vlTOPp->s_axis_tlast));
	vcdp->chgBit  (c+19,(vlTOPp->s_axis_tready));
	vcdp->chgBus  (c+20,(vlTOPp->m_axis_tdata),18);
	vcdp->chgBit  (c+21,(vlTOPp->m_axis_tvalid));
	vcdp->chgBit  (c+22,(vlTOPp->m_axis_tlast));
	vcdp->chgBit  (c+23,(vlTOPp->m_axis_tready));
    }
}
