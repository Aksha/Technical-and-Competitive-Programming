@shopstyle-admin_api_retailers @api @shopstyle_admin_api @shopstyle_portal_api @retailers @production_exclude
Feature: ShopStyle Admin Portal API v1/retailers

 ## ShopStyle Admin Portal v1/retailers API

  ## GET /retailers
  @bvt
  Scenario: Admin - Can GET all retailers from admin portal v1/retailers 
    Given we are testing the shopstyle api
    And I am an existing admin user
    And we login to the shopstyle v2 api
    When I make a GET request to v1_admin for the retailers
    Then I get back a 200 response
    And I get back more than 99 retailers in the items block

  ## POST /retailers
  @bvt
  Scenario: Admin - Can POST to admin portal v1/retailers creates a new retailer
    Given we are testing the shopstyle api
    And I am an existing admin user
    And we login to the shopstyle v2 api
    When I make a POST request to v1_admin to create a retailer with default fields
    Then I get back a 200 response
    Then I verify the retailer has the name, handle and url we set

  ## PUT /retailers/<id>
  @bvt
  Scenario: Admin - Can PUT admin portal v1/retailers update an existing retailer
    Given we are testing the shopstyle api
    And I am an existing admin user
    And we login to the shopstyle v2 api
    When I make a POST request to v1_admin to create a retailer with default fields
    Then I get back a 200 response
    Then I verify the retailer has the name, handle and url we set
    When I make a PUT request to v1_admin to update the retailer
    Then I get back a 200 response   
    And I verify the retailer has the name and url we updated

  ## GET /retailers/<id>
  @bvt
  Scenario: Admin - Can GET a retailer by id from admin portal v1/retailers
    Given we are testing the shopstyle api
    And I am an existing admin user
    And we login to the shopstyle v2 api
    Then I make a GET request to v1_admin for retailer with id 1
    Then I get back a 200 response
    And I get back the retailer Nordstrom
