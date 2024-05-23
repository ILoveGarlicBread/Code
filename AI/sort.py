num_list = [31, 59, 26, 41, 58]
# Sorted funcction
sorted_list = sorted(num_list)
print("using sorted function")
print(sorted)
# sort method
print("before sort method")
print(num_list)
num_list.sort()
print(num_list)

# Sorting with lambda function
num_list = [31, 59, 26, 41, 58]
name_list = ["John", "Paul", "George", "Ringo"]
id_name_list = list(zip(num_list, name_list))
print(id_name_list)
sorted_list = sorted(id_name_list, key=lambda x: x[1])
print(sorted_list)

num_list = [12, 45, 23, 67, 89, 34, 56, 78, 23, 45]
sorted_list = sorted(num_list, key=lambda x: x % 10)
print(num_list)
print(sorted_list)

# https://www.freecodecamp.org/news/lambda-sort-list-in-python
