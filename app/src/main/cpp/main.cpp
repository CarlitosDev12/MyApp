#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/FileInputStream.hpp>
#include <SFML/System/MemoryInputStream.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <string>
#include <filesystem>
#include <vector>
#include <ctime>
#include <map>
enum Screens
{
  Init,
  MyAppT,
  MyAppHi,
  MyApp,
  MyDatas,
  MyFiles,
  MyWrite,
  MyClock,
  MyCalculator,
  FunCommands
};
int main()
{
  Screens State = Init;
  int SubState = 0;
  int A;
  int B;
  int C;
  int Page = 1;
  int Pages = 2;
  std::filesystem::path Path("/sdcard");
  std::string SystemState = "<INIT>";
  std::string Username = "Carlos";
  std::string TextBar = "|";
  std::string Version = "v1.4.0-beta.3";
  std::string PageBar = "";
  std::string DataSave1 = "";
  std::string DataSave2 = "";
  std::string DataSave3 = "";
  bool ShowTextBar = true;
  bool Bool1 = false;
  bool Bool2 = false;
  std::vector<std::string> Lines;
  std::map<std::string, std::string> Dts;
  std::string Key;
  std::string Data;
  sf::RenderWindow Screen(sf::VideoMode::getDesktopMode(), "Screen");
  Screen.setFramerateLimit(60);
  #if defined(SFML_SYSTEM_ANDROID) || defined(SFML_SYSTEM_IOS)
    sf::Keyboard::showVirtualKeyboard(true);
  #endif
  std::cout << std::endl;
  std::cout << "Loading..." << std::endl;
  std::string Buffer = "";
  std::string LineInput = "";
  std::string Input = "";
  sf::Clock TextBarClock;
  sf::Font Font;
  std::cout << "Font : ";
  if(Font.openFromFile("roboto/Roboto-Regular.ttf"))
  {
    std::cout << "Loaded" << std::endl;
  }
  else
  {
    std::cout << "Failed" << std::endl;
    std::cout << "FATAL ERROR : Can't load font" << std::endl;
    return 1;
  }
  std::cout << "Path : ";
  if(std::filesystem::exists(Path))
  {
    std::cout << "Exists" << std::endl;
  }
  else
  {
    std::cout << "Does not exists" << std::endl;
  }
  sf::Text Text(Font);
  Text.setCharacterSize(32);
  Text.setFillColor(sf::Color::White);
  Text.setPosition({5, 5});
  sf::Text TimeFont(Font);
  TimeFont.setCharacterSize(32);
  TimeFont.setFillColor(sf::Color::White);
  TimeFont.setString("");
  TimeFont.setPosition({5, 120});
  while(Screen.isOpen())
  {
    while(const std::optional Event = Screen.pollEvent())
    {
      if(Event->is<sf::Event::Closed>())
      {
        #if defined(SFML_SYSTEM_ANDROID) || defined(SFML_SYSTEM_IOS)
          sf::Keyboard::showVirtualKeyboard(false);
        #endif
        Screen.close();
      }
      if(const auto* TextEvent = Event->getIf<sf::Event::TextEntered>())
      {
        char Character = static_cast<char>(TextEvent->unicode);
        if(Character == '\n' || Character == '\r')
        {
          if(State == Init)
          {
            if(SubState == 0)
            {
              if(Input == "Y" || Input == "y")
              {
                DataSave1 = Input;
                SubState = 1;
              }
              else if(Input == "N" || Input == "n")
              {
                Screen.close();
              }
              else
              {
                Input.clear();
              }
            }
            else if(SubState == 1)
            {
              if(Input == "CarlitosXD")
              {
                DataSave2 = Input;
                SubState = 2;
              }
              else
              {
                Input.clear();
              }
            }
            else if(SubState == 2)
            {
              if(Input == Username)
              {
                DataSave3 = Input;
                SubState = 0;
                State = MyAppT;
              }
              else
              {
                Input.clear();
              }
            }
            Input.clear();
          }
          else if(State == MyAppT)
          {
            Lines.push_back(Input);
            if(Input == "/start")
            {
              SubState = 0;
              State = MyAppHi;
            }
            if(Input == "/starttwo")
            {
              SubState = 0;
              State = MyApp;
            }
            if(Input == "/exit")
            {
              SubState = 1;
              if(SubState == 1)
              {
                #if defined(SFML_SYSTEM_ANDROID) || defined(SFML_SYSTEM_IOS)
                  sf::Keyboard::showVirtualKeyboard(false);
                #endif
                Screen.close();
              }
            }
            if(Input == "/clear")
            {
              Lines.clear();
              SubState = 0;
              Input.clear();
            }
            if(Input == "/reset")
            {
              SubState = 0;
              State = MyAppT;
            }
            if(Input == "/help" || Input == "help" || Input == "Help" || Input == "/commandlist")
            {
              SubState = 2;
            }
            if(Input == "/state")
            {
              SubState = 3;
            }
            if(Input == "/systemstate")
            {
              SubState = 4;
            }
            if(SubState == 4 && Input == "INIT")
            {
              SubState = 0;
              State = Init;
            }
            if(SubState == 4 && Input == "RUNTIME")
            {
              SubState = 0;
              State = MyApp;
            }
            if(Input == "/systemstate = RUNTIME")
            {
              SubState = 0;
              State = MyApp;
            }
            if(Input == "/systemstate = INIT")
            {
              SubState = 0;
              State = Init;
            }
            if(Input == "/appinfo")
            {
              SubState = 5;
            }
            if(Input == "/version")
            {
              SubState = 6;
            }
            if(Input == "/printinput")
            {
              SubState = 7;
              Input.clear();
            }
            if(SubState == 7)
            {
              if(Input == "/quit")
              {
                SubState = 0;
                Input.clear();
              }
              else
              {
                Lines.clear();
                Lines.push_back(Input);
                Input.clear();
              }
            }
            if(Input == "/input")
            {
              SubState = 8;
              Input.clear();
            }
            if(SubState == 8)
            {
              if(Input == "/quit")
              {
                SubState = 0;
                Input.clear();
              }
              else
              {
                Lines.clear();
                Input.clear();
              }
            }
            Input.clear();
          }
          else if(State == MyAppHi)
          {
            SubState = 1;
            if(SubState == 1)
            {
              SubState = 0;
              State = MyApp;
            }
          }
          else if(State == MyApp)
          {
            if(Input == "Quit" || Input == "/quit" || Input == "quit")
            {
              Lines.clear();
              SubState = 0;
              State = MyAppT;
            }
            if(Input == "/reset" || Input == "Reset" || Input == "reset")
            {
              SubState = 0;
              State = MyApp;
            }
            if(Input == "/state" || Input == "state" || Input == "State")
            {
              SubState = 1;
            }
            if(Input == ">")
            {
              Page++;
            }
            if(Input == "<")
            {
              Page--;
            }
            if(Input == "1" || Input == "Datas" || Input == "datas")
            {
              SubState = 0;
              State = MyDatas;
            }
            if(Input == "2" || Input == "Files" || Input == "files")
            {
              SubState = 0;
              State = MyFiles;
            }
            if(Input == "3" || Input == "Write" || Input == "write")
            {
              SubState = 0;
              State = MyWrite;
            }
            if(Input == "4" || Input == "Clock" || Input == "clock")
            {
              SubState = 0;
              State = MyClock;
            }
            if(Input == "5" || Input == "Calculator" || Input == "calculator")
            {
              SubState = 0;
              State = MyCalculator;
            }
            if(Input == "6" || Input == "Commands" || Input == "commands")
            {
              SubState = 0;
              State = FunCommands;
            }
            Lines.clear();
            Input.clear();
          }
          else if(State == MyDatas)
          {
            if(SubState == 0)
            {
              Lines.push_back(Input);
              if(Input == "/quit" || Input == "Quit" || Input == "quit")
              {
                SubState = 0;
                State = MyApp;
              }
              if(Input == "/clear")
              {
                Lines.clear();
                Input.clear();
              }
              if(Input == "/reset")
              {
                Lines.clear();
                Input.clear();
                State = MyDatas;
              }
              else if(Input == "Put" || Input == "put")
              {
                SubState = 1;
              }
              else if(Input == "Get" || Input == "get")
              {
                SubState = 3;
              }
            }
            else if(SubState == 1)
            {
              Key = Input;
              SubState = 2;
            }
            else if(SubState == 2)
            {
              Data = Input;
              Dts[Key] = Data;
              SubState = 0;
            }
            else if(SubState == 3)
            {
              Key = Input;
              if(Dts.find(Key) != Dts.end())
              {
                SubState = 4;
              }
              else
              {
                SubState = 0;
              }
            }
            else if(SubState == 4)
            {
              SubState = 0;
            }
            Input.clear();
          }
          else if(State == MyFiles)
          {
            Lines.push_back(Input);
            if(Input == "N" || Input == "n" || Input == "No" || Input == "no" || Input == "/quit" || Input == "Quit" || Input == "quit")
            {
              SubState = 0;
              State = MyApp;
            }
            if(Input == "Y" || Input == "y" || Input == "Yes" || Input == "yes")
            {
              SubState = 1;
            }
            if(Input == "/clear")
            {
              SubState = 0;
              Input.clear();
              Lines.clear();
            }
            if(Input == "/reset")
            {
              SubState = 0;
              State = MyFiles;
              Input.clear();
              Lines.clear();
            }
            Input.clear();
          }
          else if(State == MyWrite)
          {
            Lines.push_back(Input);
            if(Input == "/quit")
            {
              SubState = 0;
              Lines.clear();
              Input.clear();
              State = MyApp;
            }
            if(Input == "/clear")
            {
              Input.clear();
              Lines.clear();
            }
            if(Input == "/reset")
            {
              SubState = 0;
              Input.clear();
              Lines.clear();
              State = MyWrite;
            }
            Input.clear();
          }
          else if(State == MyClock)
          {
            SubState = 1;
            if(Input == "/quit")
            {
              SubState = 0;
              TimeFont.setString("");
              Input.clear();
              Lines.clear();
              State = MyApp;
            }
            if(Input == "/reset")
            {
              SubState = 0;
              Input.clear();
              Lines.clear();
              State = MyClock;
            }
            Input.clear();
          }
          else if(State == MyCalculator)
          {
            Lines.push_back(Input);
            if(Input == "/quit")
            {
               SubState = 0;
              Input.clear();
              Lines.clear();
              State = MyApp;
            }
            else if(Input == "/reset")
            {
              SubState = 0;
              Input.clear();
              Lines.clear();
              State = MyCalculator;
            }
            else if(Input == "/clear")
            {
              Input.clear();
              Lines.clear();
            }
            else if(SubState == 0)
            {
              if(Input == "1")
              {
                SubState = 1;
              }
              else if(Input == "2")
              {
                SubState = 4;
              }
            }
            else if(SubState == 1)
            {
              Lines.clear();
              try
              {
                A = std::stoi(Input);
                Lines.push_back(Input);
                SubState = 2;
              }
              catch(...)
              {
                //
              }
            }
            else if(SubState == 2)
            {
              try
              {
                B = std::stoi(Input);
                Lines.push_back(Input);
                C = A + B;
                SubState = 3;
              }
              catch(...)
              {
                //
              }
            }
            else if(SubState == 3)
            {
              Lines.clear();
              SubState = 0;
            }
            else if(SubState == 4)
            {
              try
              {
                A = std::stoi(Input);
                Lines.push_back(Input);
                SubState = 5;
              }
              catch(...)
              {
                //
              }
            }
            else if(SubState == 5)
            {
              try
              {
                B = std::stoi(Input);
                C = A * B;
                Lines.push_back(Input);
                SubState = 6;
              }
              catch(...)
              {
                //
              }
            }
            else if(SubState == 6)
            {
              Lines.clear();
              SubState = 0;
            }
            Input.clear();
          }
          else if(State == FunCommands)
          {
            Lines.push_back(Input);
            if(SubState == 3 || SubState == 5 || SubState == 8)
            {
              SubState = 0;
              DataSave1.clear();
              Input.clear();
            }
            else
            {
              if(Input == "/quit")
              {
                SubState = 0;
                Lines.clear();
                Input.clear();
                State = MyApp;
              }
              else if(Input == "/clear")
              {
                SubState = 0;
                Input.clear();
                Lines.clear();
              }
              else if(Input == "/reset")
              {
                SubState = 0;
                Lines.clear();
                Input.clear();
                State = FunCommands;
              }
              else if(Input == "/help")
              {
                SubState = 1;
              }
              else if(Input == "/hackerscreen")
              {
                SubState = 2;
              }
              else if(Input == "/counter")
              {
                SubState = 4;
              }
              else if(Input == "/whileword")
              {
                SubState = 6;
              }
              else if(SubState == 2)
              {
                if(Input == "Y" || Input == "y")
                {
                  SubState = 3;
                }
                else
                {
                  SubState = 0;
                }
              }
              else if(SubState == 4)
              {
                if(Input == "Y" || Input == "y")
                {
                  A = 0;
                  SubState = 5;
                }
                else
                {
                  SubState = 0;
                }
              }
              else if(SubState == 6)
              {
                if(Input == "Y" || Input == "y")
                {
                  DataSave1.clear();
                  SubState = 7;
                }
                else
                {
                  SubState = 0;
                }
              }
              else if(SubState == 7)
              {
                DataSave1 = Input + "\n";
                SubState = 8;
              }
              Input.clear();
            }
          }
        }
        else if(Character == '\b')
        {
          if(!Input.empty())
          {
            Input.pop_back();
          }
        }
        else if(TextEvent->unicode >= 32 && TextEvent->unicode < 128)
        {
          Input += Character;
        }
      }
    }
    Buffer.clear();
    if(TextBarClock.getElapsedTime().asMilliseconds() >= 500)
    {
      ShowTextBar = !ShowTextBar;
      TextBarClock.restart();
    }
    TextBar = ShowTextBar ? "|" : " ";
    switch(State)
    {
      case Init:
        SystemState = "<INIT>";
        Buffer = "Welcome!\n";
        Buffer += "Lets Login\n\n";
        Buffer += "C++ Version\n";
        Buffer += Version + "\n";
        Buffer += SystemState + "\n";
        Buffer += "By Carlos\n";
        if(SubState == 0)
        {
          Buffer += "\nDo you want continue? ( Y - N )";
          LineInput = "\n> " + Input;
        }
        if(SubState == 1)
        {
          Buffer += "\nDo you want continue? ( Y - N )\n> " + DataSave1;
          Buffer += "\nPassword:";
          LineInput = "\n> " + Input;
        }
        if(SubState == 2)
        {
          Buffer += "\nDo you want continue? ( Y - N )\n> " + DataSave1 + "\nPassword:\n> " + DataSave2 + "\n...";
          Buffer += "\nUsername:";
          LineInput = "\n> " + Input;
        }
        if(SubState == 3)
        {
          Buffer += "\nDo you want continue? ( Y - N )\n> " + DataSave1 + "\nPassword:\n> " + DataSave2 + "\n...\nUsername:\n> " + DataSave3 + "\n...";
        }
        break;
      case MyAppT:
        SystemState = "<INIT>";
        Buffer = "============================================================================================================\n";
        Buffer += "MyShell\n";
        Buffer += "------------------------------------------------------------------------------------------------------------\n";
        Buffer += "Welcome to MyShell\nWrite 'help', 'Help', '/help' or '/commandlist' for\nmore information\n";
        Buffer += "============================================================================================================";
        for(auto L : Lines)
        {
          Buffer += "\n> " + L;
        }
        LineInput = "\n> " + Input;
        if(SubState == 1)
        {
          Buffer += "\n[Press Enter]";
        }
        if(SubState == 2)
        {
          Buffer += "\n1 : /state\n";
          Buffer += "2 : /systemstate\n";
          Buffer += "3 : /appinfo\n";
          Buffer += "4 : /version\n";
          Buffer += "5 : /help\n";
          Buffer += "6 : /clear\n";
          Buffer += "7 : /exit\n";
          Buffer += "8 : /commandlist\n";
          Buffer += "9 : /start\n";
          Buffer += "10 : /systemstate = RUNTIME\n";
          Buffer += "11 : /printinput\n";
          Buffer += "12 : /input\n";
          Buffer += "13 : /reset\n";
          Buffer += "14 : /starttwo";
        }
        if(SubState == 3)
        {
          Buffer += "\n" + SystemState;
        }
        if(SubState == 4)
        {
          LineInput = "\nsystemstate> " + Input;
        }
        if(SubState == 5)
        {
          Buffer += "\nMyApp\n\n";
          Buffer += "Version " + Version + "\n";
          Buffer += "Edition C++\n";
          Buffer += SystemState + "\n";
          Buffer += "By Carlos";
        }
        if(SubState == 6)
        {
          Buffer += "\n" + Version + "\n";
          Buffer += "Name : MyShell\n";
          Buffer += "What's new?\n\n";
          Buffer += "1 : SFML Port!\n";
          Buffer += "2 : A new page system!";
        }
        if(SubState == 7)
        {
          LineInput = "\nprint> " + Input;
        }
        if(SubState == 8)
        {
          LineInput = "\ninput> " + Input;
        }
        break;
      case MyAppHi:
        Buffer = "Hi\n";
        Buffer += Username + "\n";
        LineInput = "\n[Press Enter]" + Input;
        break;
      case MyApp:
        SystemState = "<RUNTIME>";
        Buffer = "============================================================================================================\n";
        Buffer += "MyApp\n";
        Buffer += "------------------------------------------------------------------------------------------------------------\n";
        Buffer += PageBar;
        Buffer += "------------------------------------------------------------------------------------------------------------\n";
        if(Page == 1)
        {
          PageBar = "Page : " + std::to_string(Page) + " / " + std::to_string(Pages) + "  > : Next Page  < : Former Page\n"; 
          Buffer += "1 : Datas               6 : Commands\n";
          Buffer += "2 : Files\n";
          Buffer += "3 : Write\n";
          Buffer += "4 : Clock\n";
          Buffer += "5 : Calculator\n";
          Buffer += "============================================================================================================";
        }
        else if(Page == 2)
        {
          PageBar = "Page : " + std::to_string(Page) + " / " + std::to_string(Pages) + "  > : Next Page  < : Former Page\n";
          Buffer += "Nothing...\n";
          Buffer += "\n";
          Buffer += "\n";
          Buffer += "\n";
          Buffer += "\n";
          Buffer += "============================================================================================================";
        }
        if(Page >= 3)
        {
          Page = 1;
        }
        if(Page <= 0)
        {
          Page = 2;
        }
        LineInput = "\n> " + Input;
        if(SubState == 1)
        {
          Buffer += "\n" + SystemState;
        }
        break;
      case MyDatas:
        Buffer = "============================================================================================================\n";
        Buffer += "MyDatas\n";
        Buffer += "------------------------------------------------------------------------------------------------------------\n";
        Buffer += "What do you want to doing?\n";
        Buffer += "Put, Get or Quit\n";
        Buffer += "============================================================================================================";
        for(auto L : Lines)
        {
          Buffer += "\n> " + L;
        }
        LineInput = "\n> " + Input;
        if(SubState == 1)
        {
          LineInput = "\nEnter Key: >> " + Input;
        }
        if(SubState == 2)
        {
          Buffer += "\nEnter Key: >> " + Key;
          LineInput = "\nEnter Data: >> " + Input;
        }
        if(SubState == 3)
        {
          LineInput = "\nEnter Key: " + Input;
        }
        if(SubState == 4)
        {
          Buffer += "\nEnter Key: ****";
          Buffer += "\nYour Data: " + Dts[Key];
        }
        break;
      case MyFiles:
        Buffer = "============================================================================================================\n";
        Buffer += "MyFiles\n";
        Buffer += "------------------------------------------------------------------------------------------------------------\n";
        Buffer += "What do you want to doing\n";
        Buffer += "Show files? ( Y - N )\n";
        Buffer += "============================================================================================================";
        for(auto L : Lines)
        {
          Buffer += "\n> " + L;
        }
        LineInput = "\n> " + Input;
        if(SubState == 1)
        {
          Buffer += "\n";
          if(std::filesystem::exists(Path))
          {
            try
            {
              for(auto &d : std::filesystem::directory_iterator(Path))
              {
                Buffer += static_cast<std::string>(d.path()) + "\n";
              }
              Buffer += "It ends!";
            }
            catch(...)
            {
              //
            }
          }       
        }
        break;
      case MyWrite:
        Buffer = "============================================================================================================\n";
        Buffer += "MyWrite\n";
        Buffer += "------------------------------------------------------------------------------------------------------------\n";
        Buffer += "Write /quit to exit\n";
        Buffer += "============================================================================================================";
        for(auto L : Lines)
        {
          Buffer += "\n> " + L;
        }
        LineInput = "\n> " + Input;
        break;
      case MyClock:
        Buffer = "============================================================================================================\n";
        Buffer += "MyClock\n";
        Buffer += "------------------------------------------------------------------------------------------------------------\n\n";
        Buffer += "============================================================================================================";
        LineInput = "\n> " + Input;
        if(SubState == 1)
        {
          std::time_t Time = time(0);
          struct tm* Localtime = localtime(&Time);
          char BufferTime[9];
          std::strftime(BufferTime, sizeof(BufferTime), "%H:%M:%S", Localtime);
          TimeFont.setString(BufferTime);
        }
        break;
      case MyCalculator:
        Buffer = "============================================================================================================\n";
        Buffer += "MyCalculator\n";
        Buffer += "------------------------------------------------------------------------------------------------------------\n";
        Buffer += "Welcome to Calculator\n\n";
        Buffer += "Choose : 1 = Addition, 2 = Multiplicacion\n";
        Buffer += "Write 'Quit' for exit\n";
        Buffer += "============================================================================================================";
        if(SubState == 0)
        {
          for(auto L : Lines)
          {
            Buffer += "\n> " + L;
          }
          LineInput = "\n> " + Input;
        }
        if(SubState == 1)
        {
          LineInput = "\nAdd> " + Input;
        }
        if(SubState == 2)
        {
          Buffer += "\nAdd> " + std::to_string(A) + " + ";
          LineInput = Input;
        }
        if(SubState == 3)
        {
          Buffer += "\nAdd> " + std::to_string(A) + " + " + std::to_string(B) + " = " + std::to_string(C);
          LineInput = "\nIt ends!\n[Press Enter]" + Input;
        }
        if(SubState == 4)
        {
          LineInput = "\nMul> " + Input;
        }
        if(SubState == 5)
        {
          Buffer += "\nMul> " + std::to_string(A) + " x ";
          LineInput = Input;
        }
        if(SubState == 6)
        {
          Buffer += "\nMul> " + std::to_string(A) + " x " + std::to_string(B) + " = " + std::to_string(C);
          LineInput = "\nIt ends!\n[Press Enter]" + Input;
        }
        break;
      case FunCommands:
        Buffer = "============================================================================================================\n";
        Buffer += "FunCommands\n";
        Buffer += "------------------------------------------------------------------------------------------------------------\n";
        Buffer += "Write /help to meet all commands\n";
        Buffer += "============================================================================================================";
        for(auto L : Lines)
        {
          Buffer += "\n> " + L;
        }
        LineInput = "\n> " + Input;
        if(SubState == 1)
        {
          Buffer += "\n1: /quit = This command is used to exit\n";
          Buffer += "2: /clear = This command is used to clear the screen\n";
          Buffer += "3: /reset = This commands reset the state\n";
          Buffer += "4: /hackerscreen = A screen that has a lot of green words\n";
          Buffer += "5: /counter = An infinite sum of numbers\n";
          Buffer += "6: /whileword = Repeats a word a lot of time";
        }
        if(SubState == 2)
        {
          Buffer += "\nWARNING: This may impair device performance\nDo you want continue? ( Y - N )";
          LineInput = "\n?> " + Input;
        }
        if(SubState == 3)
        {
          DataSave1 += "\n\033[32mhacking.system + sys doc ) ? haxk)\nha tourn -ksk %18 sl + ((// jis:: system.out Sytsem Hacing p (Mode = Hack) { H H H H } print (haja ) ={}\njw + si12))\n";
          Buffer += DataSave1;
        }
        if(SubState == 4)
        {
          Buffer += "\nWARNING: This may impair device performance\nDo you want continue? ( Y - N )";
          LineInput = "\n?> " + Input;
        }
        if(SubState == 5)
        {
          A++;
          DataSave1 += "\n" + std::to_string(A);
          Buffer += "\n" + DataSave1;
        }
        if(SubState == 6)
        {
          Buffer += "\nWARNING: This may impair device performance\nDo you want continue? ( Y - N )";
          LineInput = "\n?> " + Input;
        }
        if(SubState == 7)
        {
          LineInput = "\nwhileword> " + Input;
        }
        if(SubState == 8)
        {
          DataSave1 += DataSave1;
          Buffer += "\n" + DataSave1;
        }
        break;
    }
    std::string Union = Buffer + LineInput + TextBar;
    Text.setString(Union);
    Screen.clear(sf::Color::Black);
    Screen.draw(TimeFont);
    Screen.draw(Text);
    Screen.display();
  }
}
