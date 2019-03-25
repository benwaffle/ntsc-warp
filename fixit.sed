s/"delay9\\n\\t"/"nop\\n\\t" "nop\\n\\t" "nop\\n\\t" "nop\\n\\t" "nop\\n\\t" "nop\\n\\t" "nop\\n\\t" "nop\\n\\t" "nop\\n\\t"/g
s/"delay8\\n\\t"/"nop\\n\\t" "nop\\n\\t" "nop\\n\\t" "nop\\n\\t" "nop\\n\\t" "nop\\n\\t" "nop\\n\\t" "nop\\n\\t"/g
s/"delay7\\n\\t"/"nop\\n\\t" "nop\\n\\t" "nop\\n\\t" "nop\\n\\t" "nop\\n\\t" "nop\\n\\t" "nop\\n\\t"/g
s/"delay6\\n\\t"/"nop\\n\\t" "nop\\n\\t" "nop\\n\\t" "nop\\n\\t" "nop\\n\\t" "nop\\n\\t"/g
s/"delay5\\n\\t"/"nop\\n\\t" "nop\\n\\t" "nop\\n\\t" "nop\\n\\t" "nop\\n\\t"/g
s/"delay4\\n\\t"/"nop\\n\\t" "nop\\n\\t" "nop\\n\\t" "nop\\n\\t"/g
s/"delay3\\n\\t"/"nop\\n\\t" "nop\\n\\t" "nop\\n\\t"/g
s/"delay2\\n\\t"/"nop\\n\\t" "nop\\n\\t"/g
s/"delay1\\n\\t"/"nop\\n\\t"/g
s/"svprt\t\%\[port\]\\n\\t"/"in\tr16,\%\[port\]\\n\\t"    ANDI_HWS/g
s/"o1bs\t\%\[port\]\\n\\t"/BLD_HWS    "out \%\[port\],r16\\n"/g
s/"o1bs\t\%\[port\]\\n"/BLD_HWS    "out \%\[port\],r16\\n"/g
