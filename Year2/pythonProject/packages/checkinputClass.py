import datetime

class CheckDateTime:
    def __init__(self):
        pass

    def is_valid_date(self, input_date):
        date = datetime.datetime.strptime(input_date, "%Y-%m-%d")
        if date >= date.today():
            return False
        else:
            return True
    
    def is_valid_time(self, input_time):
        time = datetime.datetime.strptime(input_time, "%H:%M")
        if time >= datetime.datetime.now().time():
            return False
        else:
            return True


        


