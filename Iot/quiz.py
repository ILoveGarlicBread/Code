import webbrowser

base_url = "https://black-meadow-040d15503.1.azurestaticapps.net/quiz/"

for i in range(1, 49):
    url = base_url + str(i)

webbrowser.open_new_tab(url)
