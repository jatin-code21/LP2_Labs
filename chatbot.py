import os
import webbrowser
import datetime
import wikipedia


def wishMe():
    hour = int(datetime.datetime.now().hour)
    if hour >= 0 and hour < 12:
        print("Good Morning")
    elif hour >= 12 and hour < 16:
        print("Good Afternoon")
    elif hour >= 16 and hour < 20:
        print("Good Evening")
    else:
        print("Good Night")
    print("I am codeXbeast, How may I help you?")


if __name__ == "__main__":
    wishMe()
    while True:
        print("Please tell me how may I help you")
        query = input().lower()
        if query == "exit":
            break
        tasks_dict = {
            "the time":
            lambda query: print(
                f"The time is {datetime.datetime.now().strftime('%H:%M:%S')}"),
            "what is your name":
            lambda query: print("My name is codeXbeast"),
            "how are you?":
            lambda query: print("I am fine, Thank you"),
            "who made you?":
            lambda query: print("I was built by Jatin"),
            "open code":
            lambda query: os.startfile(
                "C:\\Users\\Jatin Oza\\AppData\\Local\\Programs\\Microsoft VS Code\\code.exe"
            ),
            "search":
            lambda query: webbrowser.open("https://www.google.com/search?q=" +
                                          query.replace("search", "")),
            "open":
            lambda query: webbrowser.open(query.replace("open ", "") + ".com"),
        }

        task = None
        for k, v in tasks_dict.items():
            if k in query:
                task = v
                break

        if task:
            task(query)
        else:
            print("I am sorry, I am not able to understand you")
