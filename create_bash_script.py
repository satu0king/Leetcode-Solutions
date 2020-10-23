import json
import re
import os

destination_dir = './my_solutions'

if not os.path.exists(destination_dir):
    os.makedirs(destination_dir)

with open('metadata.json') as f:
  question_list = json.load(f)

from os import listdir
from os.path import isfile, join
saved_solutions = [f for f in listdir(destination_dir) if isfile(join(destination_dir, f))]
saved_solutions = set(map(lambda x: int(re.search('^(\d*)\.', x)[1]), saved_solutions))
f = open('get_ac.sh', 'w')

for question in question_list['stat_status_pairs']:
	if question['stat']['frontend_question_id'] in saved_solutions:
		continue
	if question['status'] == 'ac':
		str1 = 'leetcode submission {} -o {} \n'.format(question['stat']['frontend_question_id'], destination_dir)
		str1 += '\nsleep 1s\n'
		f.write(str1)
f.close()