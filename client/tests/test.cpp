#include "../source/header/objects.h"
#include "../source/header/unit.h"
#include <gtest/gtest.h>

namespace {

class objTest : public ::testing::Test {
 protected:





  virtual void SetUp() {
      q0.in(1,1);
      q1.in(2,2);
      q2.in(1,2);
      q3.in(3,3);
      q4.in(2,3 );
   
  }


  objects q0,q1,q2,q3,q4,q5,q6;

};

class unitTest : public ::testing::Test {
protected:





 virtual void SetUp() {
     q0.in(1,1);
     q1.in(2,2);
     q2.in(1,2);
     q3.in(3,3);
     q4.in(2,3);
  
 }


 objects q0,q1,q2,q3,q4,q5,q6;

};




TEST_F(objTest, getCount) {
  EXPECT_EQ(1,q0.getCount());
  EXPECT_EQ(4,q1.getCount());
  EXPECT_EQ(2,q2.getCount());
  EXPECT_EQ(9,q3.getCount());
  EXPECT_EQ(6,q4.getCount());
}

TEST_F(objTest, getVecX ) {
  //0
  ASSERT_NEAR( 0,q0.getVecX(0), 0.001);

  //1
  ASSERT_NEAR(-0.5, q1.getVecX(0), 0.001);
  ASSERT_NEAR(0.5,q1.getVecX(1), 0.001); 
  ASSERT_NEAR(-0.5,q1.getVecX(2), 0.001);
  ASSERT_NEAR(0.5,q1.getVecX(3), 0.001);

  //2
  ASSERT_NEAR(-0.5,q2.getVecX(0), 0.001);
  ASSERT_NEAR(0.5,q2.getVecX(1), 0.001); 

  //3
  ASSERT_NEAR(-0.66666, q3.getVecX(0), 0.001);
  ASSERT_NEAR( 0,q3.getVecX(1), 0.001); 
  ASSERT_NEAR( 0.66666,q3.getVecX(2), 0.001);
  ASSERT_NEAR(-0.66666,q3.getVecX(3), 0.001);
  ASSERT_NEAR( 0, q3.getVecX(4), 0.001);
  ASSERT_NEAR( 0.66666,q3.getVecX(5), 0.001); 
  ASSERT_NEAR(-0.66666,q3.getVecX(6), 0.001);
  ASSERT_NEAR( 0,q3.getVecX(7), 0.001);
  ASSERT_NEAR( 0.66666,q3.getVecX(8), 0.001);

  //4
  ASSERT_NEAR(-0.66666, q4.getVecX(0), 0.001);
  ASSERT_NEAR( 0,q4.getVecX(1), 0.001); 
  ASSERT_NEAR( 0.66666,q4.getVecX(2), 0.001);
  ASSERT_NEAR(-0.66666,q4.getVecX(3), 0.001);
  ASSERT_NEAR( 0, q4.getVecX(4), 0.001);
  ASSERT_NEAR( 0.66666,q4.getVecX(5), 0.001); 
}

TEST_F(objTest, getVecY ) {
  //0
  //ASSERT_NEAR( 0,q0.getVecY(0), 0.001);

  //1
  ASSERT_NEAR(-0.5,q1.getVecY(0), 0.001);
  ASSERT_NEAR(-0.5,q1.getVecY(1), 0.001); 
  ASSERT_NEAR(0.5,q1.getVecY(2), 0.001);
  ASSERT_NEAR(0.5,q1.getVecY(3), 0.001);

  //2
  ASSERT_NEAR(0,q2.getVecY(0), 0.001);
  ASSERT_NEAR(0,q2.getVecY(1), 0.001); 

  //3
  ASSERT_NEAR(-0.66666, q3.getVecY(0), 0.001);
  ASSERT_NEAR(-0.66666,q3.getVecY(1), 0.001); 
  ASSERT_NEAR(-0.66666,q3.getVecY(2), 0.001);
  ASSERT_NEAR( 0,q3.getVecY(3), 0.001);
  ASSERT_NEAR( 0, q3.getVecY(4), 0.001);
  ASSERT_NEAR( 0,q3.getVecY(5), 0.001); 
  ASSERT_NEAR( 0.66666,q3.getVecY(6), 0.001);
  ASSERT_NEAR( 0.66666,q3.getVecY(7), 0.001);
  ASSERT_NEAR( 0.66666,q3.getVecY(8), 0.001);

  //3
  ASSERT_NEAR(-0.5, q4.getVecY(0), 0.001);
  ASSERT_NEAR(-0.5,q4.getVecY(1), 0.001); 
  ASSERT_NEAR(-0.5,q4.getVecY(2), 0.001);
  ASSERT_NEAR( 0.5,q4.getVecY(3), 0.001);
  ASSERT_NEAR( 0.5, q4.getVecY(4), 0.001);
  ASSERT_NEAR( 0.5,q4.getVecY(5), 0.001); 
}



}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}