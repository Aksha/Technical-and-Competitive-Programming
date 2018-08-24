rule Filter_Syb8XiHe3Z{
searchResults.searchResults_data.searchTerm->include?("jeans") && true
}
rule JeansFit_SyKy2XBhZ{
searchResults.searchResults_data.searchTerm->include?(/(?i)(flair|skinny|mom\s?jeans?|tampered\s?jeans?|wedge\s?fit|slim\s?(fit|pant|straight|model|skinny|jeans|denim))/)
}
rule JeansWash_HJd6T7B2b{
searchResults.searchResults_data.searchTerm->include?(/(?i)(acid\s?wash|black|white|dark\s?wash|light\s?wash|medium\s?wash|wash)/)
}
rule JeansStyle_r1alJ4B35{
searchResults.searchResults_data.searchTerm->include?(/(?i)(vintage|ripped|embellished|patch(ed)?|distressed|embroidered)/)
}
rule JeansRise_H16WxNH26{
searchResults.searchResults_data.searchTerm->include?(/(?i)(high\s?-?(waist(ed)?|rise)|(mid|medium|low)\s?-?(rised?|waist(ed)?))/)
}
ruleresults Filter_Syb8XiHe3Z { count( "AGGREGATION_NODE_ID":"S1zUQjrxnZ","table":"COODemoTask","tags":{"searchResults.searchResults_data.searchTerm":searchResults.searchResults_data.searchTerm},"column":"jeans_count","preset":"test_destination_2","seed_brokers":"bb224.target.com:9092","format":"influx_line","topic":"DemoJeans","points":{"jeans_count":[]} ) }
ruleresults JeansFit_SyKy2XBhZ { count( "AGGREGATION_NODE_ID":"r1xYknmB2Z","table":"COODemoTask","tags":{"searchResults.searchResults_data.searchTerm":searchResults.searchResults_data.searchTerm},"column":"jeans_fit","seed_brokers":"bb224.target.com:9092","format":"influx_line","topic":"DemoJeans","preset":"test_destination_2","points":{"jeans_fit":[]} ),avg( "AGGREGATION_NODE_ID":"SkgLm4HNsf","table":"COODemoTask","tags":{"addToCart.addToCart_data.viewDetailsClick":addToCart.addToCart_data.viewDetailsClick},"column":"Akstest","topic":"metric-influx-tgt-ttc-prod-platform-engineering-thalamus","preset":"default","seed_brokers":"measure-kafka-tgt-ttc.target.com:9092","format":"influx_line","points":{"Akstest":[checkout.tax]} ) }
ruleresults JeansWash_HJd6T7B2b { count( "AGGREGATION_NODE_ID":"B1K66XHhW","table":"COODemoTask","tags":{"searchResults.searchResults_data.searchTerm":searchResults.searchResults_data.searchTerm},"column":"jeans_wash","seed_brokers":"bb224.target.com:9092","format":"influx_line","topic":"DemoJeans","preset":"test_destination_2","points":{"jeans_wash":[]} ) }
ruleresults JeansStyle_r1alJ4B35 { count( "AGGREGATION_NODE_ID":"Syeply4r34","table":"COODemoTask","tags":{"searchResults.searchResults_data.searchTerm":searchResults.searchResults_data.searchTerm},"column":"jeans_style","seed_brokers":"bb224.target.com:9092","format":"influx_line","topic":"DemoJeans","preset":"test_destination_2","points":{"jeans_style":[]} ) }
ruleresults JeansRise_H16WxNH26 { count( "AGGREGATION_NODE_ID":"B1M6lVHhW","table":"COODemoTask","tags":{"searchResults.searchResults_data.searchTerm":searchResults.searchResults_data.searchTerm},"column":"jeans_rise","seed_brokers":"bb224.target.com:9092","format":"influx_line","topic":"DemoJeans","preset":"test_destination_2","points":{"jeans_rise":[]} ) }
rulegraph Filter_Syb8XiHe3Z { (JeansFit_SyKy2XBhZ,JeansWash_HJd6T7B2b,JeansStyle_r1alJ4B35,JeansRise_H16WxNH26) }
