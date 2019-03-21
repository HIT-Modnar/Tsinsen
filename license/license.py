#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

import datetime
import os

time = datetime.datetime.now()
folder = str(os.getcwd())
folder = folder[len(folder)-5:]
print('// Source : http://www.tsinsen.com/' + folder)
print('// Author : Modnar')
print('// Date   : %s' % str(time)[:10])
