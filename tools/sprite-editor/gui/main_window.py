# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'main_window.ui'
#
# Created: Wed Jul 30 21:00:01 2014
#      by: PyQt4 UI code generator 4.10.4
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

try:
    _fromUtf8 = QtCore.QString.fromUtf8
except AttributeError:
    def _fromUtf8(s):
        return s

try:
    _encoding = QtGui.QApplication.UnicodeUTF8
    def _translate(context, text, disambig):
        return QtGui.QApplication.translate(context, text, disambig, _encoding)
except AttributeError:
    def _translate(context, text, disambig):
        return QtGui.QApplication.translate(context, text, disambig)

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName(_fromUtf8("MainWindow"))
        MainWindow.resize(617, 480)
        MainWindow.setMinimumSize(QtCore.QSize(615, 480))
        self.centralwidget = QtGui.QWidget(MainWindow)
        self.centralwidget.setObjectName(_fromUtf8("centralwidget"))
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtGui.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 617, 21))
        self.menubar.setObjectName(_fromUtf8("menubar"))
        self.menuFile = QtGui.QMenu(self.menubar)
        self.menuFile.setObjectName(_fromUtf8("menuFile"))
        self.menuNew = QtGui.QMenu(self.menuFile)
        self.menuNew.setObjectName(_fromUtf8("menuNew"))
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtGui.QStatusBar(MainWindow)
        self.statusbar.setObjectName(_fromUtf8("statusbar"))
        MainWindow.setStatusBar(self.statusbar)
        self.actionOpen = QtGui.QAction(MainWindow)
        self.actionOpen.setObjectName(_fromUtf8("actionOpen"))
        self.actionQuit = QtGui.QAction(MainWindow)
        self.actionQuit.setObjectName(_fromUtf8("actionQuit"))
        self.actionSave = QtGui.QAction(MainWindow)
        self.actionSave.setEnabled(False)
        self.actionSave.setObjectName(_fromUtf8("actionSave"))
        self.actionSave_as = QtGui.QAction(MainWindow)
        self.actionSave_as.setEnabled(False)
        self.actionSave_as.setObjectName(_fromUtf8("actionSave_as"))
        self.actionExport = QtGui.QAction(MainWindow)
        self.actionExport.setEnabled(False)
        self.actionExport.setObjectName(_fromUtf8("actionExport"))
        self.actionClose = QtGui.QAction(MainWindow)
        self.actionClose.setEnabled(False)
        self.actionClose.setObjectName(_fromUtf8("actionClose"))
        self.actionSprite = QtGui.QAction(MainWindow)
        self.actionSprite.setObjectName(_fromUtf8("actionSprite"))
        self.actionDirection_Sprite = QtGui.QAction(MainWindow)
        self.actionDirection_Sprite.setObjectName(_fromUtf8("actionDirection_Sprite"))
        self.actionResource_File = QtGui.QAction(MainWindow)
        self.actionResource_File.setObjectName(_fromUtf8("actionResource_File"))
        self.menuNew.addAction(self.actionSprite)
        self.menuNew.addAction(self.actionDirection_Sprite)
        self.menuNew.addAction(self.actionResource_File)
        self.menuFile.addAction(self.menuNew.menuAction())
        self.menuFile.addAction(self.actionOpen)
        self.menuFile.addAction(self.actionSave)
        self.menuFile.addAction(self.actionSave_as)
        self.menuFile.addAction(self.actionClose)
        self.menuFile.addSeparator()
        self.menuFile.addAction(self.actionExport)
        self.menuFile.addAction(self.actionQuit)
        self.menubar.addAction(self.menuFile.menuAction())

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(_translate("MainWindow", "StiGame::Sprite Editor", None))
        self.menuFile.setTitle(_translate("MainWindow", "File", None))
        self.menuNew.setTitle(_translate("MainWindow", "New...", None))
        self.actionOpen.setText(_translate("MainWindow", "Open...", None))
        self.actionQuit.setText(_translate("MainWindow", "Quit", None))
        self.actionSave.setText(_translate("MainWindow", "Save", None))
        self.actionSave_as.setText(_translate("MainWindow", "Save as", None))
        self.actionExport.setText(_translate("MainWindow", "Export", None))
        self.actionClose.setText(_translate("MainWindow", "Close", None))
        self.actionSprite.setText(_translate("MainWindow", "Sprite", None))
        self.actionDirection_Sprite.setText(_translate("MainWindow", "Direction Sprite", None))
        self.actionResource_File.setText(_translate("MainWindow", "Resource File", None))

