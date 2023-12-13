from plyer import notification
from datetime import datetime
notification.notify(
title = "Sample Notification",
message = "This is a sample notification",
timeout = 10
)

print(datetime.today())

