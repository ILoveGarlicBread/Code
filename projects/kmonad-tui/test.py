from textual.app import App, ComposeResult
from textual.widgets import Static, Header


class Kmonad(App):
    CSS_PATH = "test.tcss"

    def compose(self) -> ComposeResult:
        yield Header()
        yield Static("Header",classes="box",id="header")
        yield Static("One", classes="box")
        yield Static("Two", classes="box")

if __name__ == "__main__":
    app = Kmonad()
    app.run()
