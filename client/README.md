Функционирование:

    0. Отрисовка меню(класс menu.cpp)->нажать старт (частично)
	
    1. Установление соединения с сервером. (-)
	
    2. КЛиент подключается к серверу и переходит в режим ожидания другого игрока. (-)
	
    3. Подключается другой игрок. Сервер высылает обоим игрокам "11110001111". Что означает начало партии. (-)
	
    4. На сервере запускается таймер в 35 секунд. У игроков запускаются таймеры по 30 секунд(без синхронизации таймеров) (-)
	
    5. По прошествии 30 секунд клиент пересылает на сервер сформированный массив вида: (+-)
	
                    для аттаки-№ юнита, № юнита, ...
					
                    для защиты-№ юнита, № его координаты, № юнита, № координаты...
					
    6. Запуск симуляции "игры" (класс unit) (+-)
	

source:

    engine- Главный класс. вызывает все остальные. Занимается инициализацией компонентов, объявлениями и вызовом других классов и их методов.
    
    objects- класс, разбивающий поле на F_X*F_Y клеток. 
	
    Ltext.cpp- просто загрузка текстур
	
    buff.cpp, calc.cpp- устаревшие. подлежат удалению.
	
    numbers- класс для отривки цифр (рабочий)
	
    bukavki-класс для отрисовки текста (частично рабочий)
	
    connect-класс для установления соединения (не рабочий)
	
    unit-класс для "симуляции" игры. (осталось добавить урон)
	
    choose- класс выборки юнитов. (рабочий)
