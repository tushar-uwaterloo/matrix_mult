from Verilog_VCD import parse_vcd
import json

waveform = parse_vcd('verilator.vcd')

result = { 'signal': [] }

endtime = 500

for k in waveform.keys():
    signal = waveform[k]
    nets = signal['nets'][0]
    tv   = signal['tv'] 

    '''
    if nets['name'] != 'aclk' and nets['name'] != 'm_axis_tdata[18:0]':
        continue
    '''

    signal_name = "{}.{}".format(nets['hier'], nets['name'])
    signals = []
    current = 0
    data = []
    for i in range(0, endtime):
        if current < len(tv):
            current_timestamp = tv[current]
        else:
            current_timestamp = (endtime + 1, '')
        if i < current_timestamp[0]:
            signals.append('.')
        elif i == current_timestamp[0]:
            if nets['size'] == '1':
                signals.append(current_timestamp[1])
            else:
                signals.append('=')
                str_to_add = ""
                try:
                    str_to_add = int(current_timestamp[1], 2)
                except:
                    str_to_add = current_timestamp[1]
                data.append(str_to_add)
            current = current + 1
    wave = { "name": signal_name, "wave": ''.join(signals), "data": data}

    result['signal'].append(wave)
index = 0
while True:
    print(index)
    r = result['signal']
    ok = True
    for i in range(0, len(r)):
        if r[i]['wave'][index] != '.':
            ok = False
    if not ok:
        index = index + 1
    else:
        for i in range(0, len(r)):
            r[i]['wave'] = r[i]['wave'][:index] + r[i]['wave'][(index+1):]

    if index >= len(r[0]['wave']):
        break

print(json.dumps(result))
