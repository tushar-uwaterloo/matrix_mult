import argparse
from wavedrom import renderWaveForm, convert_to_svg
from Verilog_VCD import parse_vcd, get_endtime
import json


def to_json(filename, dump_signals, endtime):
    waveform = parse_vcd(filename)

    if endtime == -1:
        endtime = get_endtime()

    result = { 'signal': [] }

    for k in waveform.keys():
        signal = waveform[k]
        nets = signal['nets'][0]
        tv   = signal['tv'] 

        if len(dump_signals) != 0 and nets['name'] not in dump_signals:
            continue

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
        wave = { "name": signal_name, "wave": ''.join(signals), "data": [str(dt) for dt in data]}
        result['signal'].append(wave)

    index = 0
    while True:
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

    return json.dumps(result)

if __name__ == '__main__':
    argparser = argparse.ArgumentParser(description='Utility for converting VCD into wavedrom json')
    argparser.add_argument('filename', default='verilator.vcd')
    argparser.add_argument('-s', '--signals', nargs='+', help='signals to dump, if not indicated, will dump all signals', default=[])
    argparser.add_argument('-e', '--endtime', nargs=1, type=int, help='the endtime to dump', metavar=['endtime'], default=[-1])
    argparser.add_argument('-o', '--output', nargs=1, help='the name of output file', default=None)
    args = argparser.parse_args()

    jswaveform = to_json(args.filename, args.signals, args.endtime[0])

    if args.output is None:
        print(jswaveform)
        exit()


    output=[]
    outputfile = args.output[0]

    renderWaveForm(0,json.loads(jswaveform),output)
    svg_output = convert_to_svg(output)

    with open("{}.svg".format(outputfile),'w') as f:
       f.write( svg_output )

    with open("{}.json".format(outputfile),'w') as f:
        f.write(jswaveform)
