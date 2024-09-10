class Bag:
# Constructor without parameter
#    def __init__(self): 
#        self.data 
# Constructor with parameter
    def __init__(self, init_data=[]):
        self.data = init_data
    def add(self, x):
        self.data.append(x)
        self.len = len(self.data)
    def addtwice(self, x):
        self.add(x)
        self.add(x)

bag = Bag(['a','b','c','d'])
bag.add(1)
bag.addtwice(2)
print(bag.data)



