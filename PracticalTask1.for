      program PracticalTask1
         implicit none
         
         logical repeatFlag
         integer getOptionSelect
         real a,alpha,beta, pi
         real getArea, getMinAngle, getCosOfMinAngle
         common /variables/ a, alpha, beta, pi
         
         a = 0
         alpha = 0
         beta = 0
         pi = 3.1415926
         repeatFlag = .true.
         
         do while(repeatFlag .or. .false.)
            select case(getOptionSelect())
               case(1)
                  call inputTriangle
            
               case(2)
                  write(*,*) getArea()
      
               case(3)
                  write(*,*) getMinAngle()
      
               case(4)
                  write(*,*) getCosOfMinAngle()
      
               case(5)
                  repeatFlag = .false.
         
               case default
                  write(*,*) 'Incorrect operation'
                  
            end select
            write(*,*) ' '
         end do
      end   
      
      integer function getOptionSelect()
         implicit none
         write(*,*) 'Choose an operation'
         write(*,*) '1 - Input the variables'
         write(*,*) '2 - Find the area of the triangle'
         write(*,*) '3 - Find the minimal angle'
         write(*,*) '4 - Find the cos of minimal angle'
         write(*,*) '5 - Exit'
         read(*,*) getOptionSelect
      end
          
      subroutine inputTriangle
         implicit none
         real a,alpha,beta,pi
         common /variables/ a, alpha, beta, pi
         integer err1, err2
         err1 = 1
         err2 = 1
         do while (err1 .NE. 0 .OR. a .LE. 0)
            write(*,*) 'Enter the side of the triangle:'
            read(*,*, iostat=err1) a
            if (err1 .NE. 0 .OR. a .LE. 0) then
               write(*,*) 'Incorrect input, try again'
            end if
         end do
         err1 = 1
         do while(err1 .NE. 0 .OR. err2 .NE. 0 .OR. alpha+beta .GE. 180)
            write(*,*) 'Enter the first angle of the triangle:'
            read(*,*, iostat=err1) alpha
            if (err1 .NE. 0 .OR. alpha .LE. 0) then
               write(*,*) 'Incorrect input'
            end if
            write(*,*) 'Enter the second angle of the triangle:'
            read(*,*, iostat=err2) beta
            if (err2 .NE. 0 .OR. beta .LE. 0) then
               write(*,*) 'Incorrect input'
            end if
            
            if (alpha + beta .GE. 180) then
               write(*,*)'Incorrect input, try again'
               write(*,*)'Sum of the angles cant reach >180'
            end if
         end do
      end

      real function getArea()
         implicit none
         real a, alpha, beta, gamma, pi, buffer1, buffer2
         common /variables/ a, alpha, beta, pi
         gamma = 180-alpha-beta
         buffer1 = a**2/2
         buffer2 = sin(alpha*pi/180)*sin(beta*pi/180)/sin(gamma*pi/180)
         getArea = buffer1 * buffer2
      end 

      real function getMinAngle()
         implicit none
         real a,alpha,beta,pi,gamma
         common /variables/ a, alpha, beta, pi
         gamma = 180-alpha-beta
         getMinAngle = min(alpha,beta,gamma)
      end

      real function getCosOfMinAngle()
         implicit none
         real a,alpha,beta,pi,gamma
         common /variables/ a, alpha, beta, pi
         gamma = 180-alpha-beta
         getCosOfMinAngle = cos((min(alpha,beta,gamma))*pi/180)
      end
