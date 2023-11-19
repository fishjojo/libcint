import re

INT1E = {
    'int1e_ovlp'    : r'( \| )',
    'int1e_kin'     : r'( 0.5 \| p dot p )',
    'int1e_nuc'     : r'( \| nuc \| )',
    'int1e_rinv'    : r'( \| rinv \| )',
    'int2c2e'       : r'( \| r12 \| )',
    'int1e_r2'      : r'( \| rc dot rc \| )',
}

INT2E = {
    'int2e'         : r'( \, \| \, )',
}

def int1e_gen_dr(order):
    string = ''
    orders = []
    for i in range(order, -1, -1):
        j = order - i
        orders.append([i,j])

    for k, v in INT1E.items():
        for od in orders:
            nabla = ''
            for i in range(od[0]):
                nabla += 'nabla '
            tmp = re.sub(r'(\\\|)', r'{}\1'.format(nabla), v, 1)
            nabla = ''
            for i in range(od[1]):
                nabla += 'nabla '
            expr = re.sub(r'(\))', r'{}\1'.format(nabla), tmp, 1)

            intor_name = k + '_dr' + str(od[0]) + str(od[1])
            print('    \'' + intor_name + '\'' + f'\t\t: ({3**order}, {3**order}),')
            string += '  \'(\"' + intor_name + '\"    ' + expr + ')\n'
    return string

def int2e_gen_dr(order):
    string = ''
    orders = []
    for i in range(order, -1, -1):
        for j in range(order-i, -1, -1):
            for k in range(order-i-j, -1, -1):
                l = order-i-j-k
                if i == 0 and j != 0:
                    continue
                if k == 0 and l != 0:
                    continue
                orders.append([i,j,k,l])

    for k, v in INT2E.items():
        for od in orders:
            nabla = ''
            for i in range(od[0]):
                nabla += 'nabla '
            tmp = re.sub(r'(\\,)', r'{}\1'.format(nabla), v, 1)
            nabla = ''
            for i in range(od[1]):
                nabla += 'nabla '
            tmp1 = re.sub(r'(\\\|)', r'{}\1'.format(nabla), tmp, 1)
            nabla = ''
            for i in range(od[2]):
                nabla += 'nabla '
            tmp2 = re.sub(r'(\\, \))', r'{}\1'.format(nabla), tmp1, 1)
            nabla = ''
            for i in range(od[3]):
                nabla += 'nabla '
            expr = re.sub(r'(\))', r'{}\1'.format(nabla), tmp2, 1)

            intor_name = k + '_dr' + str(od[0]) + str(od[1]) + str(od[2]) + str(od[3])
            print('    \'' + intor_name + '\'' + f'\t\t: ({3**order}, {3**order}),')
            string += '  \'(\"' + intor_name + '\"    ' + expr + ')\n'
    return string

def gen_header():
    header = '#!/usr/bin/env clisp\n(load "gen-code.cl")\n'
    return header

def write_to_file(orders, filename, cfilename):
    content = gen_header()
    content += '\n(gen-cint \"' + cfilename +'\"\n'
    for order in orders:
        content += int1e_gen_dr(order)
        content += int2e_gen_dr(order)
    content += ')'
    with open(filename, 'w') as f:
        f.write(content)


if __name__ == '__main__':
    orders = [1,2,3,4]
    filename = 'auto_intor_ad.cl'
    cfilename = 'deriv_ad.c'
    write_to_file(orders, filename, cfilename)
