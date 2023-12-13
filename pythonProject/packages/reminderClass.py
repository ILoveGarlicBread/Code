import time
import json
from datetime import datetime
from plyer import notification

class Reminder:
    def __init__(self, title, description, date, time):
        self.title = title
        self.date = date
        self.time = time
        self.description = description

    
    def get_title(self):
        return self.title
    def set_title(self, title):
         self.title = title

    def get_description(self):
        return self.description
    def set_description(self):
        self.description = description

    def get_time(self):
        return self.time
    def set_time(self, time):
        self.time = time

    def get_date(self):
        return self.date
    def set_date(self, time):
        self.date = date



class ReminderManager:
    def __init__(self):
        self.reminders = []
    
    def add_reminder(self, title, description, date, time):
        reminder = Reminder(title, description, date, time)
        self.reminders.append(reminder)
    
    def remove_reminder(self, title):
        self.reminders = [reminder for reminder in self.reminders if reminder.get_title() != title]

    def display_reminders(self):
        for reminder in self.reminders:
            print(f"{reminder.get_title()}\nDescription: {reminder.get_description()}\nOn {reminder.get_date()}\nAt {reminder.get_time()}\n")
        
    def sort_reminders(self):
        self.reminders.sort(key=lambda x: x.date)  
        self.reminders.sort(key=lambda d: d.time, reverse = True)

    def is_empty(self):
        if len(self.reminders) == 0:
            return 1
        else:
            return 0
    def is_same_name(self,title):
        for reminder in self.reminders:
            if reminder.get_title() == title: return 1
            else: return 0

    def save_reminders(self, filename):
        with open(filename, 'w') as file:
            json.dump([vars(reminder) for reminder in self.reminders], file)
            print("Reminders saved.")

    def load_reminders(self, filename):
        with open(filename, 'r') as file:
            data = json.load(file)
            self.reminders = [Reminder(**reminder_data) for reminder_data in data]


    def save_to_markdown(self, filename):
            with open(filename, 'w') as file:
                file.write("# Reminders\n\n")
                for reminder in self.reminders:
                    file.write(f"## {reminder.title}\n")
                    file.write(f"{reminder.date}\n")
                    file.write(f"{reminder.time}\n")
                    file.write(f"{reminder.description}\n\n")

    def system_notify(self):
        #reminder = Reminder(title, description, date, time)
        now = datetime.now()
        for reminder in self.reminders:
            reminder_datetime = datetime.strptime(f"{reminder.date} {reminder.time}", "%Y-%m-%d %H:%M")               
            if now >= reminder_datetime:
                notification.notify(
                    title = reminder.title,
                    message = reminder.description,
                    timeout = 5
                )
                self.reminders.remove(reminder)
                    
            #time.sleep(30)



