QT += core gui\
      multimedia\
      multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    bishop.cpp \
    board.cpp \
    cell.cpp \
    game.cpp \
    gcell.cpp \
    ggame.cpp \
    gpromotion.cpp \
    king.cpp \
    main.cpp \
    menu.cpp \
    move.cpp \
    pawn.cpp \
    piece.cpp \
    player.cpp \
    queen.cpp \
    rook.cpp \
    knight.cpp \
    wrongmodeexception.cpp

HEADERS += \
    bishop.h \
    board.h \
    cell.h \
    game.h \
    gcell.h \
    ggame.h \
    gpromotion.h \
    king.h \
    menu.h \
    move.h \
    pawn.h \
    piece.h \
    player.h \
    queen.h \
    rook.h \
    knight.h \
    wrongmodeexception.h

FORMS += \
    menu.ui

RESOURCES
    ressources.qrc
