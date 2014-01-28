#include "SideBySideRenderWindowsQt.h"

#include <vtkDataObjectToTable.h>
#include <vtkElevationFilter.h>
#include <vtkPolyDataMapper.h>
#include <vtkQtTableView.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkSphereSource.h>
#include <vtkCubeSource.h>
#include <vtkSmartPointer.h>
#include <vtkVersion.h>
#include <vtkImageData.h>
#include <vtkSmartPointer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkInteractorStyleImage.h>
#include <vtkXMLImageDataReader.h>
#include <vtkRenderer.h>
#include <vtkImageResliceMapper.h>
#include <vtkImageMapper3D.h>
#include <vtkImageSliceMapper.h>
#include <vtkImageMapper.h>
#include <vtkActor2D.h>
#include <vtkImageSlice.h>
#include <vtkImageViewer2.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkPointPicker.h>
#include <vtkCamera.h>
#include <vtkObjectFactory.h>
#include <vtkInteractorStyle.h>
#include <vtkPoints.h>
#include <vtkCellArray.h>
#include <vtkCellData.h>
#include <vtkUnsignedCharArray.h>
#include <vtkLine.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkImageProperty.h>
#include <vtkEventQtSlotConnect.h>
#include <vtkMath.h>
#include <vtkCallbackCommand.h>
#include <qtimer.h>
#include <math.h>
#define PTR vtkSmartPointer

 vtkSmartPointer<vtkPoints> points_left_red = vtkSmartPointer<vtkPoints>::New();
 vtkSmartPointer<vtkPoints> points_left_green = vtkSmartPointer<vtkPoints>::New();
 vtkSmartPointer<vtkPoints> points_left_blue = vtkSmartPointer<vtkPoints>::New();
 vtkSmartPointer<vtkPoints> points_left_temp = vtkSmartPointer<vtkPoints>::New();

 vtkSmartPointer<vtkPoints> points_center_red = vtkSmartPointer<vtkPoints>::New();
 vtkSmartPointer<vtkPoints> points_center_green = vtkSmartPointer<vtkPoints>::New();
 vtkSmartPointer<vtkPoints> points_center_blue = vtkSmartPointer<vtkPoints>::New();
 
 vtkSmartPointer<vtkPoints> points_right_red = vtkSmartPointer<vtkPoints>::New();
 vtkSmartPointer<vtkPoints> points_right_green = vtkSmartPointer<vtkPoints>::New();
 vtkSmartPointer<vtkPoints> points_right_blue = vtkSmartPointer<vtkPoints>::New();

  
 
 int insertupdate,sliceNumberLeft;
 int cond =1;
 int mousedown =0,right_button_down;
 
 double origin_left[3]= {0.0, 0.0, 100.0};
 double p0_left_red[3] = {100.0, 0.0, 100.0};
 double p0_left_green[3] = {100.0, 0.0, 100.0};
 double p0_left_blue[3] = {100.0, 0.0, 100.0};
 
 double origin_center[3]= {0.0, 0.0, 0.0};
 double p0_center_red[3] = {120.0, 0.0, 0.0};
 double p0_center_green[3] = {120.0, 0.0, 0.0};
 double p0_center_blue[3] = {120.0, 0.0, 0.0};
 
 double origin_right[3]= {0.0, 0.0, 100.0};
 double p0_right_red[3] = {120.0, 0.0, 100.0};
 double p0_right_green[3] = {120.0, 0.0, 100.0};
 double p0_right_blue[3] = {120.0, 0.0, 100.0};

 vtkSmartPointer<vtkLine> line0_left_red = vtkSmartPointer<vtkLine>::New();
 vtkSmartPointer<vtkLine> line0_left_green = vtkSmartPointer<vtkLine>::New();
 vtkSmartPointer<vtkLine> line0_left_blue = vtkSmartPointer<vtkLine>::New();
 vtkSmartPointer<vtkLine> line0_left_temp = vtkSmartPointer<vtkLine>::New();
 
 vtkSmartPointer<vtkLine> line0_center_red = vtkSmartPointer<vtkLine>::New();
 vtkSmartPointer<vtkLine> line0_center_green = vtkSmartPointer<vtkLine>::New();
 vtkSmartPointer<vtkLine> line0_center_blue = vtkSmartPointer<vtkLine>::New();

 vtkSmartPointer<vtkLine> line0_right_red = vtkSmartPointer<vtkLine>::New();
 vtkSmartPointer<vtkLine> line0_right_green = vtkSmartPointer<vtkLine>::New();
 vtkSmartPointer<vtkLine> line0_right_blue = vtkSmartPointer<vtkLine>::New();

 int count_left_red=0,count_left_green=0,count_left_blue=0,count_center_red=0,count_center_green=0,count_center_blue=0,count_right_red=0,count_right_green=0,count_right_blue=0;
 int Color[3];
 
 vtkSmartPointer<vtkCellArray> lines_left_red = vtkSmartPointer<vtkCellArray>::New();
 vtkSmartPointer<vtkCellArray> lines_left_green = vtkSmartPointer<vtkCellArray>::New();
 vtkSmartPointer<vtkCellArray> lines_left_blue = vtkSmartPointer<vtkCellArray>::New();
 
 vtkSmartPointer<vtkCellArray> lines_center_red = vtkSmartPointer<vtkCellArray>::New();
 vtkSmartPointer<vtkCellArray> lines_center_green = vtkSmartPointer<vtkCellArray>::New();
 vtkSmartPointer<vtkCellArray> lines_center_blue = vtkSmartPointer<vtkCellArray>::New();
 
 vtkSmartPointer<vtkCellArray> lines_right_red = vtkSmartPointer<vtkCellArray>::New();
 vtkSmartPointer<vtkCellArray> lines_right_green = vtkSmartPointer<vtkCellArray>::New();
 vtkSmartPointer<vtkCellArray> lines_right_blue = vtkSmartPointer<vtkCellArray>::New();

 vtkSmartPointer<vtkImageSliceMapper> imageSliceMapper = vtkSmartPointer<vtkImageSliceMapper>::New();
 vtkSmartPointer<vtkImageSliceMapper> imageSliceMapper2 = vtkSmartPointer<vtkImageSliceMapper>::New();
 vtkSmartPointer<vtkImageSliceMapper> imageSliceMapper3 = vtkSmartPointer<vtkImageSliceMapper>::New();
 
class MouseInteractorStyle4 : public vtkInteractorStyleImage
{
  public:
    static MouseInteractorStyle4* New();

    vtkTypeMacro(MouseInteractorStyle4, vtkInteractorStyleImage);
    int check;
	virtual void OnRightButtonDown()
	{
	right_button_down = 1;
	this->StartWindowLevel();
	}
	virtual void OnRightButtonUp()
	{
	right_button_down =0;
	this->EndWindowLevel();

	}
	virtual void OnLeftButtonUp()
	{ 
		mousedown = 0;
		if(Color[0] == 255)
			count_left_red++;
        if(Color[1] == 255)
			count_left_green++;
		if(Color[2] == 255)
			count_left_blue++;



		    }

    virtual void OnLeftButtonDown() 
    {
		
		mousedown = 1;
		// Forward events
		vtkInteractorStyleImage::OnLeftButtonDown();
		int x = this->Interactor->GetEventPosition()[0];
		int y = this->Interactor->GetEventPosition()[1];
		int z= this->Interactor->GetEventPosition()[2];
				origin_left[0] = (x);//(x-40);
		   		origin_left[1]=  y;//(y-90);
				origin_left[2]= sliceNumberLeft;
				if(Color[0] == 255)
				points_left_red->InsertNextPoint(origin_left);
				else if(Color[1] == 255)
				points_left_green->InsertNextPoint(origin_left);
				else if(Color[2] == 255)
				points_left_blue->InsertNextPoint(origin_left);
	 }
     
	 virtual void OnMouseMove()
	 {
		
		 vtkInteractorStyleImage::OnMouseMove();
		 int x = this->Interactor->GetEventPosition()[0];
         int y = this->Interactor->GetEventPosition()[1];
		 int z= this->Interactor->GetEventPosition()[2];
		 cout<<"X: "<<x << " Y : " << y <<" Z "<<z<<endl;
		if(right_button_down==0)
			this->EndWindowLevel(); 
		if(mousedown==1)
			{
						if(Color[0] == 255)
						{
						p0_left_red[0] = x;//(x-40);//x;
						p0_left_red[1] = y;//(y-90);//z;
						p0_left_red[2] = sliceNumberLeft;//-y;
						points_left_red->InsertNextPoint(p0_left_red);
				        line0_left_red->GetPointIds()->SetId(0,count_left_red); //the second 0 is the index of the Origin in the vtkPoints
						line0_left_red->GetPointIds()->SetId(1,count_left_red + 1);	
						lines_left_red->InsertNextCell(line0_left_red);
                        count_left_red++;
						
						}
						if(Color[1] == 255)
						{
						p0_left_green[0] = x;
						p0_left_green[1] = y;
						p0_left_green[2] = z;
						points_left_green->InsertNextPoint(p0_left_green);
				        line0_left_green->GetPointIds()->SetId(0,count_left_green); //the second 0 is the index of the Origin in the vtkPoints
						line0_left_green->GetPointIds()->SetId(1,count_left_green + 1);	
						lines_left_green->InsertNextCell(line0_left_green);
                        count_left_green++;
						}
						if(Color[2] == 255)
						{
						p0_left_blue[0] = x;
						p0_left_blue[1] = y;
						p0_left_blue[2] = z;
						points_left_blue->InsertNextPoint(p0_left_blue);
				        line0_left_blue->GetPointIds()->SetId(0,count_left_blue); //the second 0 is the index of the Origin in the vtkPoints
						line0_left_blue->GetPointIds()->SetId(1,count_left_blue + 1);	
						lines_left_blue->InsertNextCell(line0_left_blue);
                        count_left_blue++;
						}
             }
		 
		 
    	 }
     	
};

class MouseInteractorStyleCenter4 : public vtkInteractorStyleImage
{
  public:
    static MouseInteractorStyleCenter4* New();
    vtkTypeMacro(MouseInteractorStyleCenter4, vtkInteractorStyleImage);
    	virtual void OnRightButtonDown()
	{
	right_button_down =1;
	//mousedown=0;
	this->StartWindowLevel();
	}
	virtual void OnRightButtonUp()
	{
	right_button_down =0;
	this->EndWindowLevel();

	}
	
	virtual void OnLeftButtonUp()
	{ 
		mousedown = 0;
			if(Color[0] == 255)
			count_center_red++;
        if(Color[1] == 255)
			count_center_green++;
		if(Color[2] == 255)
			count_center_blue++;



		        }

    virtual void OnLeftButtonDown() 
    {
		mousedown = 1;
		// Forward events
		vtkInteractorStyleImage::OnLeftButtonDown();
		int x = this->Interactor->GetEventPosition()[0];
		int y = this->Interactor->GetEventPosition()[1];
		int z = this->Interactor->GetEventPosition()[1];
				origin_center[0] = x;//z;
		   		origin_center[1]= y;//+20;
				origin_center[2]= z;//-(x);
				cout<<"x : "<<x <<" Y :"<<y<<" Z :"<<z;
				if(Color[0] == 255)
				points_center_red->InsertNextPoint(origin_center);
				else if(Color[1] == 255)
				points_center_green->InsertNextPoint(origin_center);
				else if(Color[2] == 255)
				points_center_blue->InsertNextPoint(origin_center);
		 }
     
	 virtual void OnMouseMove()
	 {
		
		 vtkInteractorStyleImage::OnMouseMove();
		 int x = this->Interactor->GetEventPosition()[0];
         int y = this->Interactor->GetEventPosition()[1];
		 int z = this->Interactor->GetEventPosition()[2];
		  if(right_button_down==0)
			this->EndWindowLevel(); 
		  cout<<"x : "<<x <<" Y :"<<y<<" Z :"<<z<<endl;
		  if(mousedown==1 )
			{
			//cout<<"x : "<<x <<" Y :"<<y<<" Z :"<<z<<endl;			  
						if(Color[0] == 255)
						{
						p0_center_red[0] = x;//z;
						p0_center_red[1] = y;
						p0_center_red[2] = z;//-(x);
						points_center_red->InsertNextPoint(p0_center_red);
				        line0_center_red->GetPointIds()->SetId(0,count_center_red); //the second 0 is the index of the Origin in the vtkPoints
						line0_center_red->GetPointIds()->SetId(1,count_center_red + 1);	
						lines_center_red->InsertNextCell(line0_center_red);
                        count_center_red++;
						//cout<<"ADding red";
						}
						if(Color[1] == 255)
						{
						p0_center_green[0] = x;
						p0_center_green[1] = y;//+20;
						p0_center_green[2] = z;
						points_center_green->InsertNextPoint(p0_center_green);
				        line0_center_green->GetPointIds()->SetId(0,count_center_green); //the second 0 is the index of the Origin in the vtkPoints
						line0_center_green->GetPointIds()->SetId(1,count_center_green + 1);	
						lines_center_green->InsertNextCell(line0_center_green);
                        count_center_green++;
						//cout<<"Adding green";
						}
						if(Color[2] == 255)
						{
						p0_center_blue[0] = x;
						p0_center_blue[1] = y;//+20;
						p0_center_blue[2] = z;
						points_center_blue->InsertNextPoint(p0_center_blue);
				        line0_center_blue->GetPointIds()->SetId(0,count_center_blue); //the second 0 is the index of the Origin in the vtkPoints
						line0_center_blue->GetPointIds()->SetId(1,count_center_blue + 1);	
						lines_center_blue->InsertNextCell(line0_center_blue);
                        count_center_blue++;
						//cout<<"adding blue";
						}
				
             }
		 
		 
    	 }
     

		
};


 class MouseInteractorStyleRight4 : public vtkInteractorStyleImage
{
  public:
    static MouseInteractorStyleRight4* New();
    vtkTypeMacro(MouseInteractorStyleRight4, vtkInteractorStyleImage);
    int check;
	
		virtual void OnRightButtonDown()
	{
	right_button_down =1;
	//mousedown=0;
	this->StartWindowLevel();
	}
	virtual void OnRightButtonUp()
	{
	right_button_down =0;
	this->EndWindowLevel();

	}
	virtual void OnLeftButtonUp()
	{ 
		mousedown = 0;
		if(Color[0] == 255)
			count_right_red++;
        if(Color[1] == 255)
			count_right_green++;
		if(Color[2] == 255)
			count_right_blue++;



		    }

    virtual void OnLeftButtonDown() 
    {
		mousedown = 1;
		// Forward events
		vtkInteractorStyleImage::OnLeftButtonDown();
		int x = this->Interactor->GetEventPosition()[0];
		int y = this->Interactor->GetEventPosition()[1];
		int z= this->Interactor->GetEventPosition()[2];
				origin_right[0] = x;
		   		origin_right[1]= y;
				origin_right[2]= z;
				if(Color[0] == 255)
				points_right_red->InsertNextPoint(origin_right);
				else if(Color[1] == 255)
				points_right_green->InsertNextPoint(origin_right);
				else if(Color[2] == 255)
				points_right_blue->InsertNextPoint(origin_right);
	 }
     
	 virtual void OnMouseMove()
	 {
		
		 vtkInteractorStyleImage::OnMouseMove();
		 int x = this->Interactor->GetEventPosition()[0];
         int y = this->Interactor->GetEventPosition()[1];
		 int z= this->Interactor->GetEventPosition()[2];
		cout<<"x : "<<x <<" Y :"<<y<<" Z :"<<z<<endl;
		  if(right_button_down == 0)
			  this->EndWindowLevel();
		  if(mousedown==1)
			{
				 //cout<<"X: "<<x << " Y : " << y <<" Z "<<z<<endl;
						if(Color[0] == 255)
						{
						p0_right_red[0] = (x);
						p0_right_red[1] = (y);
						p0_right_red[2] = z;
						points_right_red->InsertNextPoint(p0_right_red);
				        line0_right_red->GetPointIds()->SetId(0,count_right_red); //the second 0 is the index of the Origin in the vtkPoints
						line0_right_red->GetPointIds()->SetId(1,count_right_red + 1);	
						lines_right_red->InsertNextCell(line0_right_red);
                        count_right_red++;
						//cout<<" Inserting point X:"<<x << " Y: "<<y<<" Z: " << z<<endl;
						}
						if(Color[1] == 255)
						{
						p0_right_green[0] = x;
						p0_right_green[1] = y;
						p0_right_green[2] = z;
						points_right_green->InsertNextPoint(p0_right_green);
				        line0_right_green->GetPointIds()->SetId(0,count_right_green); //the second 0 is the index of the Origin in the vtkPoints
						line0_right_green->GetPointIds()->SetId(1,count_right_green + 1);	
						lines_right_green->InsertNextCell(line0_right_green);
                        count_right_green++;
						}
						if(Color[2] == 255)
						{
						p0_right_blue[0] = x;
						p0_right_blue[1] = y;
						p0_right_blue[2] = z;
						points_right_blue->InsertNextPoint(p0_right_blue);
				        line0_right_blue->GetPointIds()->SetId(0,count_right_blue); //the second 0 is the index of the Origin in the vtkPoints
						line0_right_blue->GetPointIds()->SetId(1,count_right_blue + 1);	
						lines_right_blue->InsertNextCell(line0_right_blue);
                        count_right_blue++;
						}
             }
		 
		 
    	 }
 
};

 
vtkStandardNewMacro(MouseInteractorStyle4);
vtkStandardNewMacro(MouseInteractorStyleCenter4);
vtkStandardNewMacro(MouseInteractorStyleRight4);
// Constructor
SideBySideRenderWindowsQt::SideBySideRenderWindowsQt() 
{
  this->setupUi(this);
	PTR<vtkXMLImageDataReader> source = PTR<vtkXMLImageDataReader>::New();
	source->SetFileName("I:/assignment-06-octree-solution (1)/assignment-06-octree-solution/headsq-half.vti");
	source->Update();
	PTR<vtkImageData> colorImage = source->GetOutput();
	colorImage->UpdateInformation();


	//Image Slice Mapper. Three mappers for three orthogonal views
	this->pushButtonBlue->setAutoFillBackground(true);	
	this->pushButtonRed->setAutoFillBackground(true);
	this->pushButtonGreen->setAutoFillBackground(true);
	
	this->pushButtonBlue->setStyleSheet("background-color: rgb(0, 0, 255); color: rgb(255, 255, 255)");
	this->pushButtonGreen->setStyleSheet("background-color: rgb(0, 255, 0); color: rgb(255, 255, 255)");
	this->pushButtonRed->setStyleSheet("background-color: rgb(255, 0, 0); color: rgb(255, 255, 255)");
	imageSliceMapper->SetInputConnection(colorImage->GetProducerPort());
    imageSliceMapper2->SetInputConnection(colorImage->GetProducerPort());
	imageSliceMapper3->SetInputConnection(colorImage->GetProducerPort());
	
	

	//Image Slice Actor  
    vtkSmartPointer<vtkImageSlice> imageSlice = vtkSmartPointer<vtkImageSlice>::New();
    imageSlice->SetMapper(imageSliceMapper);
	vtkSmartPointer<vtkImageSlice> imageSlice2 = vtkSmartPointer<vtkImageSlice>::New();
    imageSlice2->SetMapper(imageSliceMapper2);
	vtkSmartPointer<vtkImageSlice> imageSlice3 = vtkSmartPointer<vtkImageSlice>::New();
    imageSlice3->SetMapper(imageSliceMapper3);
	imageSliceMapper->SliceFacesCameraOn();
	imageSliceMapper->SetSliceNumber(30);
	//imageSliceMapper->BorderOff();
	//imageSliceMapper->BackgroundOn();
	imageSliceMapper2->SliceFacesCameraOn();
	
	//imageSliceMapper2->SliceAtFocalPointOn();
	//imageSliceMapper2->BorderOff();

	
	imageSliceMapper3->SliceFacesCameraOn();
	
	//imageSliceMapper3->SliceAtFocalPointOn();
	//imageSliceMapper3->BorderOff();
	
	//imageSlice2->RotateY(90);
	//imageSlice->RotateY(-90);

	//imageSlice3->RotateX(90);
	imageSliceMapper2->SetSliceNumber(40);
	imageSliceMapper3->SetSliceNumber(60);
	
	
	this->horizontalSliderLeft->setMinimum(imageSliceMapper->GetSliceNumberMinValue());
	this->horizontalSliderLeft->setMaximum(imageSliceMapper->GetSliceNumberMaxValue());
   
	this->horizontalSliderCenter->setMinimum(imageSliceMapper2->GetSliceNumberMinValue());
	this->horizontalSliderCenter->setMaximum(imageSliceMapper2->GetSliceNumberMaxValue());

	this->horizontalSliderRight->setMinimum(imageSliceMapper3->GetSliceNumberMinValue());
	this->horizontalSliderRight->setMaximum(imageSliceMapper3->GetSliceNumberMaxValue());
	//Setup render window
    vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
    renderWindow->SetSize(600, 600);
	
 
   vtkSmartPointer<MouseInteractorStyle4> style1 = vtkSmartPointer<MouseInteractorStyle4>::New();
   vtkSmartPointer<MouseInteractorStyleCenter4> style2 = vtkSmartPointer<MouseInteractorStyleCenter4>::New();
   vtkSmartPointer<MouseInteractorStyleRight4> style3 = vtkSmartPointer<MouseInteractorStyleRight4>::New();
   
   //=====================
   int extent[6];
   colorImage->GetExtent(extent);
 
  double origin[3];
  colorImage->GetOrigin(origin);
 
  double spacing[3];
  colorImage->GetSpacing(spacing);
 
  

  // Render and start interaction
 leftRenderer = vtkSmartPointer<vtkRenderer>::New();
  double leftViewport[4] = {0.0, 0.0, 0.33, 0.4};
  double centerViewport[4] ={0.33, 0.0, 0.66, 0.4};
  double rightViewport[4] = {0.66, 0.0, 1.0, 0.4};
  leftRenderer->AddActor(imageSlice);
  leftRenderer->ResetCamera();//----------------------
  
  // Setup both renderers
  
  renderWindow->AddRenderer(leftRenderer);
  leftRenderer->SetBackground(.6, .5, .4);  
  
  centerRenderer = vtkSmartPointer<vtkRenderer>::New();
  centerRenderer->AddActor(imageSlice2); 
  centerRenderer->ResetCamera();
  
  renderWindow->AddRenderer(centerRenderer);
  centerRenderer->SetBackground(.4, .2, .6);  
 
  
  rightRenderer = vtkSmartPointer<vtkRenderer>::New();
  rightRenderer->AddActor(imageSlice3);
  rightRenderer->ResetCamera();
  renderWindow->AddRenderer(rightRenderer);
  rightRenderer->SetBackground(.4, .5, .6);  

  // Add the sphere to the left and the cube to the right
  
  //===========================================
  vtkCamera* leftCamera = leftRenderer->GetActiveCamera();
  leftCamera->ParallelProjectionOn();
  //leftRenderer->SetBackground(1,0,0);
 
  float xc = origin[0] + 0.5*(extent[0] + extent[1])*spacing[0];
  float yc = origin[1] + 0.5*(extent[2] + extent[3])*spacing[1];
//  float xd = (extent[1] - extent[0] + 1)*spacing[0]; // not used
  float yd = (extent[3] - extent[2] + 1)*spacing[1];
 
  float d = leftCamera->GetDistance();
  leftCamera->SetParallelScale(0.5f*static_cast<float>(yd));
  cout<<"Parallel Scakle : "<<leftCamera->GetParallelScale();
  leftCamera->SetFocalPoint(xc,yc,0.0);
  leftCamera->SetPosition(xc,yc,+d);
 //===================
 //===========================================
  vtkCamera* centerCamera = centerRenderer->GetActiveCamera();
  centerCamera->ParallelProjectionOn();
  //centerRenderer->SetBackground(1,0,0);
 
  float zcC = origin[2] + 0.5*(extent[4] + extent[5])*spacing[2];
  float ycC = origin[1] + 0.5*(extent[2] + extent[3])*spacing[1];
//  float xd = (extent[1] - extent[0] + 1)*spacing[0]; // not used
  float ydC = (extent[1] - extent[0] + 1)*spacing[0];
 
  float dC = centerCamera->GetDistance();
  cout<<"dc : "<<dC<<endl;
  cout<<"zcC : "<<zcC<<endl;
  cout<<"ycC : "<<ycC<<endl;
  cout<<"ydC : "<<ydC<<endl;
  centerCamera->SetParallelScale(0.5f*static_cast<float>(ydC));
  cout<<"Parallel Scakle Center: "<<centerCamera->GetParallelScale();
  //camera->SetFocalPoint(xc,yc,0.0);
  //camera->SetPosition(xc,yc,+d);
 centerCamera->SetFocalPoint(0,ycC,zcC);
 centerCamera->SetPosition(+dC,ycC,zcC); 
 //===================
 //===========================================
  vtkCamera* rightCamera = rightRenderer->GetActiveCamera();
  rightCamera->ParallelProjectionOn();
  //rightRenderer->SetBackground(1,0,0);
 
  float zcR = origin[2] + 0.5*(extent[4] + extent[5])*spacing[2];
  cout<<"zcr : "<<zcR<<endl;

  float xcR = origin[0] + 0.5*(extent[0] + extent[1])*spacing[0];
  cout<<"xcr : "<<xcR<<endl;
  //  float xd = (extent[1] - extent[0] + 1)*spacing[0]; // not used
  float ydR = (extent[1] - extent[0] + 1)*spacing[0];
   cout<<"ydr : "<<ydR<<endl;
  float dR = rightCamera->GetDistance();
  cout<<"dr : "<<dR<<endl;
  rightCamera->SetParallelScale(0.5f*static_cast<float>(ydR));
  cout<<"Parallel Scakle right: "<<rightCamera->GetParallelScale();
  //camera->SetFocalPoint(xc,yc,0.0);
  //camera->SetPosition(xc,yc,+d);
 rightCamera->SetFocalPoint(xcR,0,zcR);
 rightCamera->SetPosition(xcR,-dR,60); 
 //===================

  this->qvtkWidgetLeft->GetRenderWindow()->GetInteractor()->SetInteractorStyle(style1);
  this->qvtkWidgetLeft->GetRenderWindow()->AddRenderer(leftRenderer);
  this->qvtkWidgetCenter->GetRenderWindow()->GetInteractor()->SetInteractorStyle(style2);
  this->qvtkWidgetCenter->GetRenderWindow()->AddRenderer(centerRenderer);
  this->qvtkWidgetRight->GetRenderWindow()->GetInteractor()->SetInteractorStyle(style3);
  this->qvtkWidgetRight->GetRenderWindow()->AddRenderer(rightRenderer);
  
  	 
  //cout<<"AFTER"<<endl;
    // Set up action signals and slots
  //this->qvtkWidgetLeft->connect(this->qvtkWidgetLeft,SIGNAL(mouseMoveEvent(QMouseEvent *event)),this,SLOT(mousemove(QMouseEvent *event)));
  this->horizontalSliderLeft->connect(this->horizontalSliderLeft,SIGNAL(valueChanged(int)),this,SLOT(setSliceNumberLeft(int))); 
  this->horizontalSliderCenter->connect(this->horizontalSliderCenter,SIGNAL(valueChanged(int)),this,SLOT(setSliceNumberCenter(int))); 
  this->horizontalSliderRight->connect(this->horizontalSliderRight,SIGNAL(valueChanged(int)),this,SLOT(setSliceNumberRight(int))); 
  this->clearLeft->connect(this->clearLeft,SIGNAL(clicked()),this,SLOT(clearleft()));
  this->clearRight->connect(this->clearRight,SIGNAL(clicked()),this,SLOT(clearright()));
  this->clearCenter->connect(this->clearCenter,SIGNAL(clicked()),this,SLOT(clearcenter()));

  //this->pushButtonCenter->connect(this->pushButtonCenter,SIGNAL(clicked()),this,SLOT(renderCenter()));
   //this->pushButtonRight->connect(this->pushButtonRight,SIGNAL(clicked()),this,SLOT(renderRight()));
    this->pushButtonBlue->connect(this->pushButtonBlue,SIGNAL(clicked()),this,SLOT(renderBlueColor()));
	this->pushButtonGreen->connect(this->pushButtonGreen,SIGNAL(clicked()),this,SLOT(renderGreenColor()));
	this->pushButtonRed->connect(this->pushButtonRed,SIGNAL(clicked()),this,SLOT(renderRedColor()));
	QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(renderLeft()));
	connect(timer, SIGNAL(timeout()), this, SLOT(renderCenter()));
	connect(timer, SIGNAL(timeout()), this, SLOT(renderRight()));
    timer->start(10);
}

void SideBySideRenderWindowsQt::renderBlueColor()
{
	Color[0] = 0;
	Color[1] = 0;
	Color[2] = 255;
}
void SideBySideRenderWindowsQt::renderGreenColor()
{
	Color[0] = 0;
	Color[1] = 255;
	Color[2] = 0;
}
void SideBySideRenderWindowsQt::renderRedColor()
{
	Color[0] = 255;
	Color[1] = 0;
	Color[2] = 0;
}

void SideBySideRenderWindowsQt::renderLeft()
{
	linesPolyData_left_red = vtkSmartPointer<vtkPolyData>::New();
	linesPolyData_left_red->SetPoints(points_left_red);
	linesPolyData_left_red->SetLines(lines_left_red);
	linesPolyData_left_red->Update();
	//cout<<"Rendering : :"<<points_left_red->GetNumberOfPoints() << " : "<< lines_left_red->GetNumberOfCells();
	mapper_left_red = vtkSmartPointer<vtkPolyDataMapper>::New();
	actor_left_red = vtkSmartPointer<vtkActor>::New();
	mapper_left_red->SetInput(linesPolyData_left_red);
	mapper_left_red->Update();
	actor_left_red->SetMapper(mapper_left_red);
    actor_left_red->GetProperty()->SetLineWidth(5);
    actorprop_left_red = vtkSmartPointer<vtkProperty>::New();
	actorprop_left_red->SetColor(255,0,0);
	actor_left_red->SetProperty(actorprop_left_red);
	leftRenderer->AddActor(actor_left_red);
	
	this->qvtkWidgetLeft->GetRenderWindow()->GetInteractor()->ReInitialize();
	this->qvtkWidgetLeft->GetRenderWindow()->GetInteractor()->Render();

	this->qvtkWidgetLeft->GetRenderWindow()->AddRenderer(leftRenderer);
	this->qvtkWidgetLeft->GetRenderWindow()->Render();
	this->qvtkWidgetLeft->update();
	linesPolyData_left_green = vtkSmartPointer<vtkPolyData>::New();
	linesPolyData_left_green->SetPoints(points_left_green);
	linesPolyData_left_green->SetLines(lines_left_green);
	linesPolyData_left_green->Update();
	mapper_left_green = vtkSmartPointer<vtkPolyDataMapper>::New();
    actor_left_green = vtkSmartPointer<vtkActor>::New();
	mapper_left_green->SetInput(linesPolyData_left_green);
	mapper_left_green->Update();
	actor_left_green->SetMapper(mapper_left_green);
    actor_left_green->GetProperty()->SetLineWidth(5);
	actorprop_left_green = vtkSmartPointer<vtkProperty>::New();
	actorprop_left_green->SetColor(0,255,0);
	actor_left_green->SetProperty(actorprop_left_green);
	leftRenderer->AddActor(actor_left_green);
	this->qvtkWidgetLeft->GetRenderWindow()->GetInteractor()->Render();
	this->qvtkWidgetLeft->GetRenderWindow()->AddRenderer(leftRenderer);
	this->qvtkWidgetLeft->GetRenderWindow()->Render();
	this->qvtkWidgetLeft->update();
	linesPolyData_left_blue = vtkSmartPointer<vtkPolyData>::New();
	linesPolyData_left_blue->SetPoints(points_left_blue);
	linesPolyData_left_blue->SetLines(lines_left_blue);
	linesPolyData_left_blue->Update();
	mapper_left_blue = vtkSmartPointer<vtkPolyDataMapper>::New();
    actor_left_blue = vtkSmartPointer<vtkActor>::New();
	mapper_left_blue->SetInput(linesPolyData_left_blue);
	mapper_left_blue->Update();
	actor_left_blue->SetMapper(mapper_left_blue);
    actor_left_blue->GetProperty()->SetLineWidth(5);
	actorprop_left_blue = vtkSmartPointer<vtkProperty>::New();
    actorprop_left_blue->SetColor(0,0,255);
	actor_left_blue->SetProperty(actorprop_left_blue);
	leftRenderer->AddActor(actor_left_blue);
	this->qvtkWidgetLeft->GetRenderWindow()->GetInteractor()->Render();
	this->qvtkWidgetLeft->GetRenderWindow()->AddRenderer(leftRenderer);
	this->qvtkWidgetLeft->GetRenderWindow()->Render();
	this->qvtkWidgetLeft->update();
	//points_left->Reset();
	//lines_left->Reset();
	//count_left = 0;
}
void SideBySideRenderWindowsQt::renderCenter()
{
	
	linesPolyData_center_red = vtkSmartPointer<vtkPolyData>::New();
	linesPolyData_center_red->SetPoints(points_center_red);
	linesPolyData_center_red->SetLines(lines_center_red);
	linesPolyData_center_red->Update();
	mapper_center_red = vtkSmartPointer<vtkPolyDataMapper>::New();
    actor_center_red = vtkSmartPointer<vtkActor>::New();
	mapper_center_red->SetInput(linesPolyData_center_red);
	mapper_center_red->Update();
	
	actor_center_red->SetMapper(mapper_center_red);
    actor_center_red->GetProperty()->SetLineWidth(5);
    actorprop_center_red = vtkSmartPointer<vtkProperty>::New();
	actorprop_center_red->SetColor(255,0,0);
	actor_center_red->SetProperty(actorprop_center_red);
	centerRenderer->AddActor(actor_center_red);
	//this->qvtkWidgetLeft->GetRenderWindow()->FullScreenOn
	this->qvtkWidgetCenter->GetRenderWindow()->GetInteractor()->Render();
	this->qvtkWidgetCenter->GetRenderWindow()->AddRenderer(centerRenderer);
	this->qvtkWidgetCenter->GetRenderWindow()->Render();
	this->qvtkWidgetCenter->update();
	linesPolyData_center_green = vtkSmartPointer<vtkPolyData>::New();
	linesPolyData_center_green->SetPoints(points_center_green);
	linesPolyData_center_green->SetLines(lines_center_green);
	linesPolyData_center_green->Update();
	mapper_center_green = vtkSmartPointer<vtkPolyDataMapper>::New();
    actor_center_green = vtkSmartPointer<vtkActor>::New();
	mapper_center_green->SetInput(linesPolyData_center_green);
	mapper_center_green->Update();
	actor_center_green->SetMapper(mapper_center_green);
    actor_center_green->GetProperty()->SetLineWidth(5);
	actorprop_center_green = vtkSmartPointer<vtkProperty>::New();
	actorprop_center_green->SetColor(0,255,0);
	actor_center_green->SetProperty(actorprop_center_green);
	centerRenderer->AddActor(actor_center_green);
	this->qvtkWidgetCenter->GetRenderWindow()->GetInteractor()->Render();
	this->qvtkWidgetCenter->GetRenderWindow()->AddRenderer(centerRenderer);
	this->qvtkWidgetCenter->GetRenderWindow()->Render();
	this->qvtkWidgetCenter->update();
	linesPolyData_center_blue = vtkSmartPointer<vtkPolyData>::New();
	linesPolyData_center_blue->SetPoints(points_center_blue);
	linesPolyData_center_blue->SetLines(lines_center_blue);
	linesPolyData_center_blue->Update();
	mapper_center_blue = vtkSmartPointer<vtkPolyDataMapper>::New();
    actor_center_blue = vtkSmartPointer<vtkActor>::New();
	mapper_center_blue->SetInput(linesPolyData_center_blue);
	mapper_center_blue->Update();
	actor_center_blue->SetMapper(mapper_center_blue);
    actor_center_blue->GetProperty()->SetLineWidth(5);
	actorprop_center_blue = vtkSmartPointer<vtkProperty>::New();
    actorprop_center_blue->SetColor(0,0,255);
	actor_center_blue->SetProperty(actorprop_center_blue);
	centerRenderer->AddActor(actor_center_blue);
	this->qvtkWidgetCenter->GetRenderWindow()->GetInteractor()->Render();
	this->qvtkWidgetCenter->GetRenderWindow()->AddRenderer(centerRenderer);
	this->qvtkWidgetCenter->GetRenderWindow()->Render();
	this->qvtkWidgetCenter->update();

}

void SideBySideRenderWindowsQt::renderRight()
{
	linesPolyData_right_red = vtkSmartPointer<vtkPolyData>::New();
	linesPolyData_right_red->SetPoints(points_right_red);
	linesPolyData_right_red->SetLines(lines_right_red);
	linesPolyData_right_red->Update();
	mapper_right_red = vtkSmartPointer<vtkPolyDataMapper>::New();
    actor_right_red = vtkSmartPointer<vtkActor>::New();
	mapper_right_red->SetInput(linesPolyData_right_red);
	mapper_right_red->Update();
	actor_right_red->SetMapper(mapper_right_red);
    actor_right_red->GetProperty()->SetLineWidth(5);
    actorprop_right_red = vtkSmartPointer<vtkProperty>::New();
	actorprop_right_red->SetColor(255,0,0);
	actor_right_red->SetProperty(actorprop_right_red);
	rightRenderer->AddActor(actor_right_red);
	this->qvtkWidgetRight->GetRenderWindow()->GetInteractor()->Render();
	this->qvtkWidgetRight->GetRenderWindow()->AddRenderer(rightRenderer);
	this->qvtkWidgetRight->GetRenderWindow()->Render();
	this->qvtkWidgetRight->update();
	linesPolyData_right_green = vtkSmartPointer<vtkPolyData>::New();
	linesPolyData_right_green->SetPoints(points_right_green);
	linesPolyData_right_green->SetLines(lines_right_green);
	linesPolyData_right_green->Update();
	mapper_right_green = vtkSmartPointer<vtkPolyDataMapper>::New();
    actor_right_green = vtkSmartPointer<vtkActor>::New();
	mapper_right_green->SetInput(linesPolyData_right_green);
	mapper_right_green->Update();
	actor_right_green->SetMapper(mapper_right_green);
    actor_right_green->GetProperty()->SetLineWidth(5);
	actorprop_right_green = vtkSmartPointer<vtkProperty>::New();
	actorprop_right_green->SetColor(0,255,0);
	actor_right_green->SetProperty(actorprop_right_green);
	rightRenderer->AddActor(actor_right_green);
	this->qvtkWidgetRight->GetRenderWindow()->GetInteractor()->Render();
	this->qvtkWidgetRight->GetRenderWindow()->AddRenderer(rightRenderer);
	this->qvtkWidgetRight->GetRenderWindow()->Render();
	this->qvtkWidgetRight->update();
	linesPolyData_right_blue = vtkSmartPointer<vtkPolyData>::New();
	linesPolyData_right_blue->SetPoints(points_right_blue);
	linesPolyData_right_blue->SetLines(lines_right_blue);
	linesPolyData_right_blue->Update();
	mapper_right_blue = vtkSmartPointer<vtkPolyDataMapper>::New();
    actor_right_blue = vtkSmartPointer<vtkActor>::New();
	mapper_right_blue->SetInput(linesPolyData_right_blue);
	mapper_right_blue->Update();
	actor_right_blue->SetMapper(mapper_right_blue);
    actor_right_blue->GetProperty()->SetLineWidth(5);
	actorprop_right_blue = vtkSmartPointer<vtkProperty>::New();
    actorprop_right_blue->SetColor(0,0,255);
	actor_right_blue->SetProperty(actorprop_right_blue);
	rightRenderer->AddActor(actor_right_blue);
	this->qvtkWidgetRight->GetRenderWindow()->GetInteractor()->Render();
	this->qvtkWidgetRight->GetRenderWindow()->AddRenderer(rightRenderer);
	this->qvtkWidgetRight->GetRenderWindow()->Render();
	this->qvtkWidgetRight->update();

}
void SideBySideRenderWindowsQt::clearleft()
{
	//cout<<"value"<<a;

	points_left_red->Reset();
	points_left_green->Reset();
	points_left_blue->Reset();
	count_left_red=0;count_left_green=0;count_left_blue=0;
	lines_left_red->Reset();
	lines_left_green->Reset();
	lines_left_blue->Reset();
	this->qvtkWidgetLeft->GetRenderWindow()->RemoveRenderer(leftRenderer);
	this->qvtkWidgetLeft->GetRenderWindow()->AddRenderer(leftRenderer);
	this->qvtkWidgetLeft->GetRenderWindow()->Render();
	this->qvtkWidgetLeft->update();

}
void SideBySideRenderWindowsQt::clearcenter()
{
	//cout<<"value"<<a;

	points_center_red->Reset();
	points_center_green->Reset();
	points_center_blue->Reset();
	count_center_red=0;count_center_green=0;count_center_blue=0;
	lines_center_red->Reset();
	lines_center_green->Reset();
	lines_center_blue->Reset();
	this->qvtkWidgetCenter->GetRenderWindow()->RemoveRenderer(centerRenderer);
	this->qvtkWidgetCenter->GetRenderWindow()->AddRenderer(centerRenderer);
	this->qvtkWidgetCenter->GetRenderWindow()->Render();
	this->qvtkWidgetCenter->update();

}
void SideBySideRenderWindowsQt::clearright()
{
	//cout<<"value"<<a;

	points_right_red->Reset();
	points_right_green->Reset();
	points_right_blue->Reset();
	count_right_red =0;count_right_green =0;
count_right_blue =0;	
lines_right_red->Reset();
	lines_right_green->Reset();
	lines_right_blue->Reset();
	this->qvtkWidgetRight->GetRenderWindow()->RemoveRenderer(rightRenderer);
	this->qvtkWidgetRight->GetRenderWindow()->AddRenderer(rightRenderer);
	this->qvtkWidgetRight->GetRenderWindow()->Render();
	this->qvtkWidgetRight->update();

}
void SideBySideRenderWindowsQt::setSliceNumberLeft(int a)
{
	//cout<<"value"<<a;
	sliceNumberLeft=a;
	imageSliceMapper->SetSliceNumber(a);
	
	this->qvtkWidgetLeft->GetRenderWindow()->RemoveRenderer(leftRenderer);
	this->qvtkWidgetLeft->GetRenderWindow()->AddRenderer(leftRenderer);
	this->qvtkWidgetLeft->GetRenderWindow()->Render();
	this->qvtkWidgetLeft->update();

}
void SideBySideRenderWindowsQt::setSliceNumberCenter(int a)
{
	cout<<"value"<<a;
	
	//emit updateValue(a);
	imageSliceMapper2->SetSliceNumber(a);
	this->qvtkWidgetCenter->update();
	//emit updatevalue();

}
void SideBySideRenderWindowsQt::setSliceNumberRight(int a)
{
	cout<<"value"<<a;
	imageSliceMapper3->SetSliceNumber(a);
	this->qvtkWidgetRight->update();


}


void SideBySideRenderWindowsQt::slotExit() 
{
  qApp->exit();
}
 SideBySideRenderWindowsQt::~SideBySideRenderWindowsQt() {
 imageSliceMapper= NULL;
 imageSliceMapper2= NULL;
 imageSliceMapper3= NULL;
 };