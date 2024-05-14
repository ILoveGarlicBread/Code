list1=['a','b','c','d']
list2=[1,2,3,4]
zipped_list= list(zip(list1,list2))
print(zipped_list)

# variables contain items of list2 in zipped list
second_items = [item[1] for item in zipped_list]
print(second_items)
