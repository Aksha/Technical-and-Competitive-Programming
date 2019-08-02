#!/bin/env ruby
# encoding: utf-8

require 'oj'
require 'json'
require 'open4'
require 'time'
require 'base64'

### ShopStyle Admin Portal API v1 ###################################################################

def admin_v1_companies
  "v1/companies"
end

def admin_v1_company_name(name)
  "v1/companies/name/#{name}"
end

def admin_v1_company_retailers(rid)
  "v1/companies/retailer/#{rid}"
end

def admin_v1_company_user(uid)
  "v1/companies/user/#{uid}"
end

def admin_v1_company(cid)
  "v1/companies/#{cid}"
end

def admin_v1_retailers
  "v1/retailers"
end

def admin_v1_retailer(rid)
  "v1/retailers/#{rid}"
end

def admin_v1_retailer_name(name)
  "v1/companies/name/#{name}"
end

def admin_v1_users
  "v1/users"
end

def admin_v1_user(uid)
  "v1/users/#{uid}"
end

def admin_v1_organizations
  "v1/organizations"
end

def admin_v1_organizations_user(id)
  "v1/organizations/#{id}"
end

def admin_v1_user_activity(id)
  "v1/userActivity/organizations/#{id}"
end

#########################################################################################

Given(/^we login to the shopstyle v1 portal api$/) do 
  step "I am an existing admin user"
  step "we login to the shopstyle v1 admin api"
end

## Requests ###############################################################

## ADMIN Portal - COMPANIES ######################################################

When(/^I make a GET request to v1_admin for all the companies$/) do
  options = {}
  options[:portal_admin_api] = true
  @response = api_request(admin_v1_companies, "shopstyle", "GET", options)
end

When(/^I make a GET request to v1_admin for company with name "([^"]*)"$/) do |company_name|
  options = {}
  options[:portal_admin_api] = true
  @response = api_request(admin_v1_company_name(URI::encode(company_name)), "shopstyle", "GET", options)
end

When(/^I make a GET request to v1_admin for company with retailer (\d+)$/) do |retailer_id|
  options = {}
  options[:portal_admin_api] = true
  @response = api_request(admin_v1_company_retailers(retailer_id), "shopstyle", "GET", options)
end

When(/^I make a GET request to v1_admin for company with user (\d+)$/) do |user_id|
  options = {}
  options[:portal_admin_api] = true
  @response = api_request(admin_v1_company_user(user_id), "shopstyle", "GET", options)
end

When(/^I make a GET request to v1_admin for company id (\d+)$/) do |company_id|
  options = {}
  options[:portal_admin_api] = true
  @response = api_request(admin_v1_company(company_id), "shopstyle", "GET", options)
end

Given(/^I make a POST request to v1_admin to create a company$/) do
  timestamp = Time.now.to_i.to_s
  stamp = timestamp + [SecureRandom.hex].pack('H*').gsub(/[^0-9a-z]/i, '')  # Magic
  @company_name = "QA Company ##{stamp}"
  @company_handle = "QaCompanyHandle#{stamp}"

  options = {}
  options[:portal_admin_api] = true
  options[:payload] = {"name"=>"#{@company_name}", "handle"=>"#{@company_handle}"}
  @response = api_request(admin_v1_companies, "shopstyle", "POST", options)
end

When(/^I make a PUT request to v1_admin to update the company$/) do
  timestamp = Time.now.to_i.to_s
  stamp = timestamp + [SecureRandom.hex].pack('H*').gsub(/[^0-9a-z]/i, '')  # Magic
  @updated_company_name = "QA Company Updated ##{stamp}"
  @updated_company_handle = "QaCompanyHandleUpdated#{stamp}"

  options = {}
  options[:portal_admin_api] = true
  options[:payload] = {"id"=>@company_id, "name"=>"#{@updated_company_name}", "handle"=>"#{@updated_company_handle}"}

  @response = api_request(admin_v1_companies, "shopstyle", "PUT", options)
end

Then(/^I get back more than (\d+) companies in the items block$/) do |companies_expected|
  doc = Oj::Doc.open(@response)
    @companies = doc.fetch('items')
  doc.close

  assert_operator @companies.size, :>, companies_expected.to_i
end

Then(/^I get back the company Nordstrom in the items block$/) do
  doc = Oj::Doc.open(@response)
    @company_id = doc.fetch('items/1/id')
    @company_name = doc.fetch('items/1/name')
    @company_retailers = doc.fetch('items/1/retailers')
  doc.close

  step 'the company I get back is named "Nordstrom"'
  step "the company I get back has id of 16"
end

Then(/^my company is created$/) do
  step "I get back a 200 response"

  doc = Oj::Doc.open(@response)
    @company_id = doc.fetch('id')
    company_name = doc.fetch('name')
    company_handle = doc.fetch('handle')
    company_retailers = doc.fetch('retailers')
  doc.close

  assert_equal @company_name, company_name
  assert_equal @company_handle, company_handle

  @company_name = company_name
  @company_handle = company_handle
end

Given(/^I verify the company has the name and handle we set$/) do
  doc = Oj::Doc.open(@response)
    company_name = doc.fetch('name')
    company_handle = doc.fetch('handle')
  doc.close

  assert_equal @company_name, company_name
  assert_equal @company_handle, company_handle
end

Given(/^I verify the company has the name and handle we updated$/) do
  @company_name = @updated_company_name
  @company_handle = @updated_company_handle

  step "I verify the company has the name and handle we set"
end

## ADMIN v1 - RETAILERS ##############################################################

When(/^I make a GET request to v1_admin for the retailers$/) do
  options = {}
  options[:portal_admin_api] = true
  @response = api_request(admin_v1_retailers, "shopstyle", "GET", options)
end

Then(/^I get back the retailer Nordstrom$/) do
  doc = Oj::Doc.open(@response)
    retailer_name = doc.fetch('name')
    retailer_id = doc.fetch('id')
  doc.close
  assert_equal "Nordstrom", retailer_name
  assert_equal 1, retailer_id
end

When(/^I make a GET request to v1_admin for retailer with id (\d+)$/) do |retailer_id|
  options = {}
  options[:portal_admin_api] = true
  @response = api_request(admin_v1_retailer(retailer_id), "shopstyle", "GET", options)
end

Then(/^I get back more than (\d+) retailers in the items block$/) do |retailers_expected|
  doc = Oj::Doc.open(@response)
    @retailers = doc.fetch('items')
  doc.close

  assert_operator @retailers.size, :>, retailers_expected.to_i
end

When(/^I make a POST request to v(\d+)_admin to create a retailer with default fields$/) do |arg1|
  timestamp = Time.now.to_i.to_s
  stamp = timestamp + [SecureRandom.hex].pack('H*').gsub(/[^0-9a-z]/i, '')
  @retailer_name = "QA Retailer ##{stamp}"
  @retailer_handle = "QaRetailerHandle#{stamp}"
  @retailer_url = ["http://www.shopstyleqa.com"]

  options = {}
  options[:portal_admin_api] = true
  options[:payload] = {"name"=>"#{@retailer_name}",
    "handle"=>"#{@retailer_handle}","locale"=>"en_US","urls"=>@retailer_url,
    "companyId"=>0,"defaultBrandId"=>0,"hasColorsAndSizes"=>false,
    "defaultProductState"=>"NEW"}
  @response = api_request(admin_v1_retailers, "shopstyle", "POST", options)
end

Given(/^I verify the retailer has the name, handle and url we set$/) do
  doc = Oj::Doc.open(@response)
    retailer_name = doc.fetch('name')
    retailer_handle = doc.fetch('handle')
    retailer_url = doc.fetch('urls')
    @retailer_id = doc.fetch('id')
  doc.close
  puts retailer_url
  assert_equal @retailer_name, retailer_name
  assert_equal @retailer_handle, retailer_handle
  assert_equal @retailer_url, retailer_url
end

Given(/^I verify the retailer has the name and url we updated$/) do
  @retailer_name = @updated_retailer_name
  @retailer_url = @updated_retailer_url

  step "I verify the retailer has the name, handle and url we set"
end


When(/^I make a PUT request to v(\d+)_admin to update the retailer$/) do |arg1|
  timestamp = Time.now.to_i.to_s
  stamp = timestamp + [SecureRandom.hex].pack('H*').gsub(/[^0-9a-z]/i, '')  # Magic
  @updated_retailer_name = "QA Retailer Updated ##{stamp}"
  @updated_retailer_url = ["http://www.shopstyleupdated.com"]
  options = {}
  options[:portal_admin_api] = true
  options[:payload] = { "name"=>"#{@updated_retailer_name}", "urls"=>@updated_retailer_url, "ebatesStoreId"=>@retailer_id }
  @response = api_request(admin_v1_retailer(@retailer_id), "shopstyle", "PUT", options)
end

## ADMIN v1 - USERS ######################################################

When(/^I make a GET request to v1_admin for new created user$/) do 
  options = {}
  options[:portal_admin_api] = true
  @response = api_request(admin_v1_user(@new_user_id), "shopstyle", "GET", options)
  puts "==> New user_id = #{@new_user_id}" if @verbose
end

Then(/^I get a success response and new user for admin testing is created$/) do
  step "I get back a 200 response"

  doc = Oj::Doc.open(@response)
    newUser = doc.fetch('newUser') 
    @new_user_id = doc.fetch('user/id')
  doc.close

  puts "==> New user_id = #{@new_user_id}" if @verbose
  assert_equal true, newUser
  refute_nil @new_user_id
end

When(/^I make a GET request to v1_admin for users with intact email$/) do 
  options = {}
  options[:portal_admin_api] = true
  options[:params] = "authDebug=1&email=collectiveqa@gmail.com&includeStackTrace=1&limit=25&offset=0&pid=shopstyle"
  @response = api_request(admin_v1_users, "shopstyle", "GET", options)
end

When(/^I make a GET request to v1_admin for users with partial email$/) do 
  options = {}
  options[:portal_admin_api] = true
  options[:params] = "authDebug=1&email=qatesting&includeStackTrace=1&limit=25&offset=0&pid=shopstyle"
  @response = api_request(admin_v1_users, "shopstyle", "GET", options)
end

When(/^I make a GET request to v1_admin for users with no match email$/) do 
  options = {}
  options[:portal_admin_api] = true
  options[:params] = "authDebug=1&email=qatestingtesting&includeStackTrace=1&limit=25&offset=0&pid=shopstyle"
  @response = api_request(admin_v1_users, "shopstyle", "GET", options)
end

Given(/^I verify the search result of the users$/) do
  doc = Oj::Doc.open(@response)
    @user_number = doc.fetch('metadata/count')
  doc.close
  puts "Users search result = #{@user_number}"  if @verbose
end

Then(/^I get back more than (\d+) users$/) do |users_expected|
  assert_operator @user_number, :>, users_expected.to_i
end

Then(/^I get back only (\d+) users$/) do |users_expected|
  assert_equal @user_number, users_expected.to_i
end

When(/^I make a PUT request to v1_admin to assign the Talbots to new created user$/) do
  @company_id = "8" # Talbots
  options = {}
  options[:portal_admin_api] = true
  options[:payload] = { "companyId"=>"#{@company_id}","deleted"=>false,"locale"=>"en_US","userType"=>"Standard"}
  @response = api_request(admin_v1_user(@new_user_id), "shopstyle", "PUT", options)
end

When(/^I make a PUT request to v1_admin to assign new user type to new created user$/) do
  options = {}
  options[:portal_admin_api] = true
  options[:payload] = { "companyId"=>"#{@company_id}","deleted"=>false,"locale"=>"en_US","userType"=>"Celebrity"}
  @response = api_request(admin_v1_user(@new_user_id), "shopstyle", "PUT", options)
end

Given(/^I verify the company of the user$/) do
  doc = Oj::Doc.open(@response)
    @company_name = doc.fetch('company/name')
  doc.close
  puts "Users search result = #{@company_name}"  if @verbose
  assert_equal @company_name, "Talbots"
end

Given(/^I verify the user type of the user$/) do
  doc = Oj::Doc.open(@response)
    @user_type = doc.fetch('userType')
  doc.close
  puts "Users search result = #{@user_type}"  if @verbose
  assert_equal @user_type, "Celebrity"
end

## ADMIN v1 - ORGANIZATIONS ######################################################

When(/^I make a GET request to v1_admin for search potential cpa user with partner id$/) do
  options = {}
  options[:portal_admin_api] = true
  options[:params] = "apiKey=#{@user_partner_id}&includeStackTrace=1&limit=25&offset=0"
  @response = api_request(admin_v1_organizations, "shopstyle", "GET", options)
  step "I get a success response and get potential cpa user id"
end

Then(/^I get a success response and get potential cpa user id$/) do
  step "I get back a 200 response"

  doc = Oj::Doc.open(@response)
    @items_id = doc.fetch('items/id')
  doc.close
  puts "==> New items_id = #{@items_id}" if @verbose
end

Then(/^I make a PUT request to v1_admin for approve applied user as cpa user$/) do
  options = {}
  options[:portal_admin_api] = true
  options[:params] = "includeStackTrace=1"
  options[:payload] = {"applicationStatus"=>"Approved","justifications"=>["Unique Visitors and/or Followers meet requirements"]}
  @response = api_request(admin_v1_organizations_user(@items_id), "shopstyle", "PUT", options)
  doc = Oj::Doc.open(@response)
    @user_contactEmail = doc.fetch('contactEmail')
  doc.close
end
