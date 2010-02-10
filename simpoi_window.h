#ifndef SIMPOI_WINDOW_H
#define SIMPOI_WINDOW_H

/*
#include <QtGui/QMainWindow>

namespace Ui
{
    class simpoi_window;
}

class simpoi_window : public QMainWindow
{
    Q_OBJECT

public:
    simpoi_window(QWidget *parent = 0);
    ~simpoi_window();

private:
    Ui::simpoi_window *ui;
};
*/

#include <QTimer>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE
class QSlider;
QT_END_NAMESPACE

class SimpoiWidget;

class SimpoiWindow : public QWidget
{
    Q_OBJECT

public:
    SimpoiWindow();

private:
    SimpoiWidget *poi_view;
    QAction *actionLoad_Pattern;
    QAction *actionSave_Pattern;
    QAction *actionShow_Paths;
    QWidget *centralWidget;
    QGroupBox *poi1_group;
    QFrame *poi1_vline;
    QLabel *path1_angle_label;
    QLabel *poi1_direction_label;
    QSlider *path1_speed_slider;
    QSlider *poi1_speed_slider;
    QRadioButton *poi1_cc_radio;
    QLabel *poi1_angle_label;
    QLabel *path1_direction_label;
    QSlider *poi1_angle_slider;
    QLabel *path1_speed_label;
    QSlider *path1_angle_slider;
    QLabel *poi1_speed_label;
    QRadioButton *path1_cc_radio;
    QRadioButton *poi1_clockwise_radio;
    QRadioButton *path1_clockwise_radio;
    QLineEdit *path1_height_edit;
    QLineEdit *path1_width_edit;
    QComboBox *poi1_presets_combo;
    QPushButton *poi1_reset_button;
    QLabel *poi1_presets_label;
    QLabel *path1_height_label;
    QLabel *path1_width_label;
    QLineEdit *path1_center_y;
    QLineEdit *path1_center_x;
    QLabel *path1_center_label;

    QGroupBox *poi2_group;
    QFrame *poi2_vline;
    QLabel *path2_angle_label;
    QLabel *poi2_direction_label;
    QSlider *path2_speed_slider;
    QSlider *poi2_speed_slider;
    QRadioButton *poi2_cc_radio;
    QLabel *poi2_angle_label;
    QLabel *path2_direction_label;
    QSlider *poi2_angle_slider;
    QLabel *path2_speed_label;
    QSlider *path2_angle_slider;
    QLabel *poi2_speed_label;
    QRadioButton *path2_cc_radio;
    QRadioButton *poi2_clockwise_radio;
    QRadioButton *path2_clockwise_radio;
    QLineEdit *path2_height_edit;
    QLineEdit *path2_width_edit;
    QComboBox *poi2_presets_combo;
    QPushButton *poi2_reset_button;
    QLabel *poi2_presets_label;
    QLabel *path2_height_label;
    QLabel *path2_width_label;
    QLineEdit *path2_center_y;
    QLineEdit *path2_center_x;
    QLabel *path2_center_label;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuSimPoi;
    QMenu *menuFile;
};

#endif // SIMPOI_WINDOW_H
