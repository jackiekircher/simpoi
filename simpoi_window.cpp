#include <QtGui>
#include <qvalidator.h>
#include "simpoi_window.h"
#include "simpoi_widget.h"

/*
#include "ui_simpoi_window.h"

simpoi_window::simpoi_window(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::simpoi_window)
{
    ui->setupUi(this);
}

simpoi_window::~simpoi_window()
{
    delete ui;
}
*/

SimpoiWindow::SimpoiWindow()
{
    poi_view = new SimpoiWidget;
    QTimer *timer = new QTimer(poi_view);
    connect(timer, SIGNAL(timeout()), poi_view, SLOT(update()));
    timer->start(20);

    QValidator *validator = new QIntValidator(0,800,this);

    poi1_group = new QGroupBox;
    poi1_group->setTitle("poi 1 (blue)");
    poi1_group->setFixedWidth(370);
    {
        QGridLayout *grid = new QGridLayout;
        poi1_speed_label = new QLabel;
        poi1_speed_label->setFixedWidth(180);
        poi1_speed_label->setText("poi speed");
        poi1_speed_slider = new QSlider(Qt::Horizontal);
        poi1_speed_slider->setTickInterval(2);
        poi1_speed_slider->setTickPosition(QSlider::TicksBelow);
        poi1_speed_slider->setMaximum(16);
        poi1_angle_label = new QLabel;
        poi1_angle_label->setText("poi start angle");
        poi1_angle_slider = new QSlider(Qt::Horizontal);
        poi1_angle_slider->setTickInterval(90);
        poi1_angle_slider->setTickPosition(QSlider::TicksBelow);
        poi1_angle_slider->setMaximum(360);
        poi1_angle_slider->setTracking(true);
        poi1_direction_label = new QLabel;
        poi1_direction_label->setText("poi direction");
        poi1_clockwise_radio = new QRadioButton;
        poi1_clockwise_radio->setText("clockwise");
        poi1_cc_radio = new QRadioButton;
        poi1_cc_radio->setText("counter-clockwise");
        poi1_cc_radio->setChecked(true);
        QButtonGroup *poi1_buttons = new QButtonGroup;
        poi1_buttons->addButton(poi1_clockwise_radio);
        poi1_buttons->addButton(poi1_cc_radio);
        poi1_presets_label = new QLabel;
        poi1_presets_label->setText("presets");
        poi1_presets_combo = new QComboBox;
        poi1_reset_button = new QPushButton;
        poi1_reset_button->setText("reset poi");
        poi1_reset_button->setMaximumWidth(100);
        poi1_vline = new QFrame;
        poi1_vline->setFrameStyle(QFrame::VLine);
        poi1_vline->setFrameShadow(QFrame::Sunken);
        poi1_vline->setLineWidth(0);
        poi1_vline->setMidLineWidth(1);
        path1_speed_label = new QLabel;
        path1_speed_label->setText("path speed");
        path1_speed_slider = new QSlider(Qt::Horizontal);
        path1_speed_slider->setTickInterval(2);
        path1_speed_slider->setTickPosition(QSlider::TicksBelow);
        path1_speed_slider->setMaximum(8);
        path1_angle_label = new QLabel;
        path1_angle_label->setText("path start angle");
        path1_angle_slider = new QSlider(Qt::Horizontal);
        path1_angle_slider->setTickInterval(90);
        path1_angle_slider->setTickPosition(QSlider::TicksBelow);
        path1_angle_slider->setMaximum(360);
        path1_angle_slider->setTracking(true);
        path1_direction_label = new QLabel;
        path1_direction_label->setText("path direction");
        path1_clockwise_radio = new QRadioButton;
        path1_clockwise_radio->setText("clockwise");
        path1_cc_radio = new QRadioButton;
        path1_cc_radio->setText("counter-clockwise");
        path1_cc_radio->setChecked(true);
        path1_height_label = new QLabel;
        path1_height_label->setText("path height:");
        path1_height_edit = new QLineEdit;
        path1_height_edit->setMaximumWidth(50);
        path1_height_edit->setValidator(validator);
        QHBoxLayout *height1 = new QHBoxLayout;
        height1->addWidget(path1_height_label,Qt::AlignLeft);
        height1->addWidget(path1_height_edit,Qt::AlignRight);
        path1_width_label = new QLabel;
        path1_width_label->setText("path width:");
        path1_width_edit = new QLineEdit;
        path1_width_edit->setMaximumWidth(50);
        path1_height_edit->setValidator(validator);
        QHBoxLayout *width1 = new QHBoxLayout;
        width1->addWidget(path1_width_label,Qt::AlignLeft);
        width1->addWidget(path1_width_edit,Qt::AlignRight);
        path1_center_label = new QLabel;
        path1_center_label->setText("path center:");
        path1_center_x = new QLineEdit;
        path1_center_x->setFixedWidth(30);
        path1_height_edit->setValidator(validator);
        path1_center_y = new QLineEdit;
        path1_center_y->setFixedWidth(30);
        path1_height_edit->setValidator(validator);
        QHBoxLayout *center1 = new QHBoxLayout;
        center1->addWidget(path1_center_label,Qt::AlignLeft);
        center1->addWidget(path1_center_x,Qt::AlignRight);
        center1->addWidget(path1_center_y,Qt::AlignRight);

        grid->addWidget(poi1_speed_label,0,0);
        grid->addWidget(poi1_speed_slider,1,0);
        grid->addWidget(poi1_angle_label,2,0);
        grid->addWidget(poi1_angle_slider,3,0);
        grid->addWidget(poi1_direction_label,4,0);
        grid->addWidget(poi1_clockwise_radio,5,0);
        grid->addWidget(poi1_cc_radio,6,0);
        grid->addWidget(poi1_presets_label,7,0);
        grid->addWidget(poi1_presets_combo,8,0);
        grid->addWidget(poi1_reset_button,9,0,Qt::AlignHCenter);
        grid->addWidget(poi1_vline,0,1,10,1);
        grid->addWidget(path1_speed_label,0,2);
        grid->addWidget(path1_speed_slider,1,2);
        grid->addWidget(path1_angle_label,2,2);
        grid->addWidget(path1_angle_slider,3,2);
        grid->addWidget(path1_direction_label,4,2);
        grid->addWidget(path1_clockwise_radio,5,2);
        grid->addWidget(path1_cc_radio,6,2);
        grid->addLayout(height1,7,2);
        grid->addLayout(width1,8,2);
        grid->addLayout(center1,9,2);

        poi1_group->setLayout(grid);
    }


    poi2_group = new QGroupBox;
    poi2_group->setTitle("poi 2 (pink)");
    poi2_group->setFixedWidth(370);
    {
        QGridLayout *grid = new QGridLayout;
        poi2_speed_label = new QLabel;
        poi2_speed_label->setText("poi speed");
        poi2_speed_label->setFixedWidth(180);
        poi2_speed_slider = new QSlider(Qt::Horizontal);
        poi2_speed_slider->setTickInterval(2);
        poi2_speed_slider->setTickPosition(QSlider::TicksBelow);
        poi2_speed_slider->setMaximum(16);
        poi2_angle_label = new QLabel;
        poi2_angle_label->setText("poi start angle");
        poi2_angle_slider = new QSlider(Qt::Horizontal);
        poi2_angle_slider->setTickInterval(90);
        poi2_angle_slider->setTickPosition(QSlider::TicksBelow);
        poi2_angle_slider->setMaximum(360);
        poi2_angle_slider->setTracking(true);
        poi2_direction_label = new QLabel;
        poi2_direction_label->setText("poi direction");
        poi2_clockwise_radio = new QRadioButton;
        poi2_clockwise_radio->setText("clockwise");
        poi2_clockwise_radio->setChecked(true);
        poi2_clockwise_radio->setChecked(true);
        poi2_cc_radio = new QRadioButton;
        poi2_cc_radio->setText("counter-clockwise");
        QButtonGroup *poi2_buttons = new QButtonGroup;
        poi2_buttons->addButton(poi2_clockwise_radio);
        poi2_buttons->addButton(poi2_cc_radio);
        poi2_presets_label = new QLabel;
        poi2_presets_label->setText("presets");
        poi2_presets_combo = new QComboBox;
        poi2_reset_button = new QPushButton;
        poi2_reset_button->setText("reset poi");
        poi2_reset_button->setMaximumWidth(100);
        poi2_vline = new QFrame;
        poi2_vline->setFrameStyle(QFrame::VLine);
        poi2_vline->setFrameShadow(QFrame::Sunken);
        poi2_vline->setLineWidth(0);
        poi2_vline->setMidLineWidth(1);
        path2_speed_label = new QLabel;
        path2_speed_label->setText("path speed");
        path2_speed_slider = new QSlider(Qt::Horizontal);
        path2_speed_slider->setTickInterval(2);
        path2_speed_slider->setTickPosition(QSlider::TicksBelow);
        path2_speed_slider->setMaximum(6);
        path2_angle_label = new QLabel;
        path2_angle_label->setText("path start angle");
        path2_angle_slider = new QSlider(Qt::Horizontal);
        path2_angle_slider->setTickInterval(90);
        path2_angle_slider->setTickPosition(QSlider::TicksBelow);
        path2_angle_slider->setMaximum(360);
        path2_angle_slider->setTracking(true);
        path2_direction_label = new QLabel;
        path2_direction_label->setText("path direction");
        path2_clockwise_radio = new QRadioButton;
        path2_clockwise_radio->setText("clockwise");
        path2_cc_radio = new QRadioButton;
        path2_cc_radio->setText("counter-clockwise");
        path2_cc_radio->setChecked(true);
        path2_height_label = new QLabel;
        path2_height_label->setText("path height:");
        path2_height_edit = new QLineEdit;
        path2_height_edit->setMaximumWidth(50);
        path1_height_edit->setValidator(validator);
        QHBoxLayout *height2 = new QHBoxLayout;
        height2->addWidget(path2_height_label,Qt::AlignLeft);
        height2->addWidget(path2_height_edit,Qt::AlignRight);
        path2_width_label = new QLabel;
        path2_width_label->setText("path width:");
        path2_width_edit = new QLineEdit;
        path2_width_edit->setMaximumWidth(50);
        path1_height_edit->setValidator(validator);
        QHBoxLayout *width2 = new QHBoxLayout;
        width2->addWidget(path2_width_label,Qt::AlignLeft);
        width2->addWidget(path2_width_edit,Qt::AlignRight);
        path2_center_label = new QLabel;
        path2_center_label->setText("path center:");
        path2_center_x = new QLineEdit;
        path2_center_x->setFixedWidth(30);
        path1_height_edit->setValidator(validator);
        path2_center_y = new QLineEdit;
        path2_center_y->setFixedWidth(30);
        path1_height_edit->setValidator(validator);
        QHBoxLayout *center2 = new QHBoxLayout;
        center2->addWidget(path2_center_label,Qt::AlignLeft);
        center2->addWidget(path2_center_x,Qt::AlignRight);
        center2->addWidget(path2_center_y,Qt::AlignRight);

        grid->addWidget(poi2_speed_label,0,0);
        grid->addWidget(poi2_speed_slider,1,0);
        grid->addWidget(poi2_angle_label,2,0);
        grid->addWidget(poi2_angle_slider,3,0);
        grid->addWidget(poi2_direction_label,4,0);
        grid->addWidget(poi2_clockwise_radio,5,0);
        grid->addWidget(poi2_cc_radio,6,0);
        grid->addWidget(poi2_presets_label,7,0);
        grid->addWidget(poi2_presets_combo,8,0);
        grid->addWidget(poi2_reset_button,9,0,Qt::AlignHCenter);
        grid->addWidget(poi2_vline,0,1,10,1);
        grid->addWidget(path2_speed_label,0,2);
        grid->addWidget(path2_speed_slider,1,2);
        grid->addWidget(path2_angle_label,2,2);
        grid->addWidget(path2_angle_slider,3,2);
        grid->addWidget(path2_direction_label,4,2);
        grid->addWidget(path2_clockwise_radio,5,2);
        grid->addWidget(path2_cc_radio,6,2);
        grid->addLayout(height2,7,2);
        grid->addLayout(width2,8,2);
        grid->addLayout(center2,9,2);

        poi2_group->setLayout(grid);
    }

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(poi_view);

    QVBoxLayout *menuLayout = new QVBoxLayout;
    menuLayout->addWidget(poi1_group);
    menuLayout->addWidget(poi2_group);

    // Signals and Slots
    connect(poi1_speed_slider, SIGNAL(valueChanged(int)), poi_view, SLOT(poi1_speed_change(int)));
    connect(poi1_angle_slider, SIGNAL(valueChanged(int)), poi_view, SLOT(poi1_angle_change(int)));
    connect(path1_speed_slider, SIGNAL(valueChanged(int)), poi_view, SLOT(path1_speed_change(int)));
    connect(path1_angle_slider, SIGNAL(valueChanged(int)), poi_view, SLOT(path1_angle_change(int)));
    connect(poi1_clockwise_radio, SIGNAL(pressed()), poi_view, SLOT(poi1_clockwise()));
    connect(poi1_cc_radio, SIGNAL(pressed()), poi_view, SLOT(poi1_cc()));
    connect(path1_clockwise_radio, SIGNAL(pressed()), poi_view, SLOT(path1_clockwise()));
    connect(path1_cc_radio, SIGNAL(pressed()), poi_view, SLOT(path1_cc()));
    connect(path1_height_edit, SIGNAL(textChanged(const QString&)), poi_view, SLOT(path1_height_changed(const QString&)));
    connect(path1_width_edit, SIGNAL(textChanged(const QString&)), poi_view, SLOT(path1_width_changed(const QString&)));
    connect(path1_center_x, SIGNAL(textChanged(const QString&)), poi_view, SLOT(path1_centerx_changed(const QString&)));
    connect(path1_center_y, SIGNAL(textChanged(const QString&)), poi_view, SLOT(path1_centery_changed(const QString&)));

    mainLayout->addLayout(menuLayout, 1);
    setLayout(mainLayout);

    setWindowTitle(tr("SimPoi"));
}
