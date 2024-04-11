from blessed import Terminal

term = Terminal()

print(term.home + term.clear)
print(term.move_y(1) + term.underline + term.center('KMONAD TUI'))
while True:
    with term.cbreak():
        val = term.inkey()
        if val == 'q':
            break
        print(term.move_y(2) + 'You pressed: ' + str(val))
